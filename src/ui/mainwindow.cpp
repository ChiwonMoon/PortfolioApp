#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 기본 크기만 설정
    resize(800, 600);
    setWindowTitle("PortfolioApp");
    
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}