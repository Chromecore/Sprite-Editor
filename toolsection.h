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
    void on_EyedropButton_toggled(bool checked);

    void on_MirrorButton_toggled(bool checked);

    void on_ColorButton_clicked();

private:
    Ui::ToolSection *ui;
};

#endif // TOOLSECTION_H
