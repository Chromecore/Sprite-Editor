/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvasSize = 32;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Confirms canvas size selection to create Canvas. Locks options so canvas cannot be changed again.
//Resets option box when new project is created.
void MainWindow::on_confirmCanvasSizeButton_clicked()
{
    ui->spriteSizeComboBox->setEnabled(false);
    ui->confirmCanvasSizeButton->setEnabled(false);
}

//Sets internal canvas size setting before Canvas is created. If default uption is selected, confirm canvas button
//is disabled. If any other option is selected, confirm canvas button is enabled to allow canvas creation.
void MainWindow::on_spriteSizeComboBox_currentIndexChanged(int index)
{
    if (index == 0){
        ui->confirmCanvasSizeButton->setEnabled(false);
    }
    else{
        Model::instance->setSpriteSize(index * 8);
        ui->confirmCanvasSizeButton->setEnabled(true);
    }
}

