/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include <QFileDialog>
#include "model.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Sprite Sheet Project"), "",
           tr("Sprite Sheet Project (*.ssp);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        Model::instance->saveFile(fileName);
    }
}


void MainWindow::on_actionLoad_triggered()
{
    Model::instance->loadFile();
}

