/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef TOOLSECTION_H
#define TOOLSECTION_H

#include <QWidget>

namespace Ui {
class ToolSection;
}

class ToolSection : public QWidget
{
    Q_OBJECT

public:
    explicit ToolSection(QWidget *parent = nullptr);
    ~ToolSection();


private slots:
    //Method used to set up eyedrop functionality in model.cpp and to toggle eyedrop button in UI
    void on_EyedropButton_toggled(bool checked);

    //Method used to set up mirror functionality when drawing and to toggle mirror button in UI
    void on_MirrorButton_toggled(bool checked);

    //Method used to create window to select new pen color. Also updates color button in UI
    void on_ColorButton_clicked();

private:
    Ui::ToolSection *ui;
};

#endif // TOOLSECTION_H
