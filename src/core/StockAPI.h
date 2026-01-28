#pragma once

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "StockData.h"

class StockAPI : public QObject
{
	Q_OBJECT

public:
	explicit StockAPI(QObject* parent = nullptr);

	// 주식 데이터 요청 함수
	void fetchStock(const QString& symbol);

signals:
	// 데이터를 다 받으면
	void dataReceived(const StockData& data);
	// 에러가 나면
	void errorOccurred(QString message);

private slots:
	// 네트워크 응답이 오면 처리
	void onResult(QNetworkReply* reply);

private:
	QNetworkAccessManager* manager;	// 통신을 담당하는 qt 객체
};