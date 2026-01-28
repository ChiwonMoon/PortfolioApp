#pragma once

#include <QMainWindow>
#include "core/StockAPI.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void onRefreshClicked();
    void updataUI(const StockData& data);

private:
    Ui::MainWindow* ui;
    StockAPI *api;
};