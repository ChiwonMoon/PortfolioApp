#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // API 객체 생성
    api = new StockAPI(this);

    // 버튼 클릭 시
    connect(ui->btnRefresh, &QPushButton::clicked, this, &MainWindow::onRefreshClicked);

    // 데이터 도착 시
    connect(api, &StockAPI::dataReceived, this, &MainWindow::updataUI);

    // 시작하자마자 한번 가져오기
    onRefreshClicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updataUI(const StockData& data)
{
    ui->labelSymbol->setText("AAPL");
    ui->labelPrice->setText(QString("$%1").arg(data.currentPrice));

    // 변동률 계산 (현재가 - 전일종가) / 전일종가 * 100
    double change = 0.0;
    if (data.prevClose != 0) {
        change = ((data.currentPrice - data.prevClose) / data.prevClose) * 100.0;
    }
    ui->labelChange->setText(QString("%1%").arg(change, 0, 'f', 2)); // 소수점 2자리

    // (팁) 상승이면 빨간색, 하락이면 파란색으로 바꾸기
    if (change > 0) {
        ui->labelChange->setStyleSheet("color: red;");
    }
    else {
        ui->labelChange->setStyleSheet("color: blue;");
    }
}

void MainWindow::onRefreshClicked()
{
    // 버튼 누르면 "로딩 중..." 표시
    ui->labelPrice->setText("Loading...");

    // 애플(AAPL) 주식 요청
    api->fetchStock("AAPL");
}