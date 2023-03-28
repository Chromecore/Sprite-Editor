/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "toolsection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ToolSection tools;
    ui->gridLayout->addWidget(&tools, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

