/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef EDITINGSECTION_H
#define EDITINGSECTION_H

#include <QWidget>

namespace Ui {
class EditingSection;
}

class EditingSection : public QWidget
{
    Q_OBJECT

public:
    explicit EditingSection(QWidget *parent = nullptr);
    ~EditingSection();

private:
    bool mousePressed;
    Ui::EditingSection *ui;
    // colors a pixel at a point of an event if the event happened inside the pixmap
    void colorPixel(QPoint eventPoint);
    void getPixelColor(QPoint eventPoint);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void repaintSection();
};

#endif // EDITINGSECTION_H
