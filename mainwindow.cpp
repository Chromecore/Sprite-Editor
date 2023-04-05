/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include <QFileDialog>
#include "model.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    connect(Model::instance,
            &Model::invalidFile,
            this,
            &MainWindow::showFileError);
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
void MainWindow::showFileError() {
    QMessageBox::critical(this, tr("Invalid file"), tr("The selected file was not a valid .ssp file. "
                                                       "Files must be a JSON object with equal int values for height and width, "
                                                       "a numberOfFrames int value, and a frames object containing at least "
                                                       "one frame."));
}

