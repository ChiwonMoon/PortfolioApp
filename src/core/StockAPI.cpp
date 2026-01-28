#include "StockAPI.h"
#include "Config.h"
#include <QJsonDocument>
#include <QJsonObject.h>
#include <QUrlQuery>
#include <QDebug>

StockAPI::StockAPI(QObject* parent)
	: QObject(parent)
{
	// 통신 관리자 생성
	manager = new QNetworkAccessManager(this);
}

void StockAPI::fetchStock(const QString& symbol)
{
	// URL
	QUrl url(Config::BASE_URL + "/quote");

	QUrlQuery query;
	query.addQueryItem("symbol", symbol);
	query.addQueryItem("token", Config::API_KEY);
	url.setQuery(query);

	// 요청
	QNetworkRequest request(url);
	QNetworkReply* reply = manager->get(request);

	// 응답
	connect
	(
		reply, 
		&QNetworkReply::finished,
		[this, reply]() {
			this->onResult(reply);
	});

	qDebug() << "Requesting stock data for:" << symbol;
}

void StockAPI::onResult(QNetworkReply* reply)
{
	// 메모리 해제 예약
	reply->deleteLater();

	// 에러체크
	if (reply->error() != QNetworkReply::NoError)
	{
		qDebug() << "Network Error:" << reply->errorString();
		emit errorOccurred(reply->errorString());
		return;
	}

	// 데이터 읽기
	QByteArray responseData = reply->readAll();

	// JSON 파싱
	QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
	QJsonObject jsonObj = jsonDoc.object();

	if (!jsonObj.contains("c"))
	{
		qDebug() << "Invalid Data format";
		return;
	}

	// 데이터를 구조체에 담기
	StockData data;

	data.currentPrice = jsonObj["c"].toDouble();
	data.highPrice = jsonObj["h"].toDouble();
	data.lowPrice = jsonObj["l"].toDouble();
	data.openPrice = jsonObj["o"].toDouble();
	data.prevClose = jsonObj["pc"].toDouble();

	// 무료 API는 종목명 x
	data.name = "Unknown";

	qDebug() << "Data Received! Price:" << data.currentPrice;

	// UI
	emit dataReceived(data);
}