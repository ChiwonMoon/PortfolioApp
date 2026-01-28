#include <QApplication>
#include "ui/mainwindow.h"
#include "core/StockAPI.h"
#include <qdebug.h>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}