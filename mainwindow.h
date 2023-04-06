/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Shows error dialog box when file loaded improperly.
    void showFileError();

private slots:
    //Creates file explorer window to allocate file location and name.
    void on_actionSave_triggered();

    //Opens file explorer to load .ssp file and set up current workspace to match file specifications.
    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
