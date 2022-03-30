#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //zmena pre git 2
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator is Fetylegg");
    w.show();
    return a.exec();
}
