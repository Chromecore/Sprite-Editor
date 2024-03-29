/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "mainwindow.h"
#include <QApplication>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model::init();
    MainWindow w;
    w.show();
    return a.exec();
}
