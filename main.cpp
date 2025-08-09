#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-color: #f2f2f2");
    w.show();
    return a.exec();
}
