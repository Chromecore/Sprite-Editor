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
    //Opens up dialog box, searches for .ssp files, and allows user to save .ssp file to a specific name.
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Sprite Sheet Project"), "",
           tr("Sprite Sheet Project (*.ssp);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        //Goes to save function to finish saving the file.
        Model::instance->saveFile(fileName);
    }
}

void MainWindow::on_actionLoad_triggered()
{
    Model::instance->loadFile();
}

void MainWindow::showFileError() {
    QString message;

    //Displays error message if loaded file does not meet program specifications.
    message.fromStdString("The selected file was not a valid .ssp file.\n"
                          "Files msut be a JSON object with equal int values for height and width.\n"
                          "The object must have a numberOfFrames int value and a frames object containing at least one frame.\n"
                          "Valid width/height values are 4, 8, 16, and 32.");
    QMessageBox::critical(this, tr("Invalid file"), message);
}

