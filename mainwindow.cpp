/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "model.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setup saving and loading through the menubar
    QAction *saveAction = ui->menubar->addAction("Save");
    QAction *loadAction = ui->menubar->addAction("Load");
    connect(saveAction, &QAction::triggered, Model::instance, &Model::saveFile);
    connect(loadAction, &QAction::triggered, Model::instance, &Model::loadFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

