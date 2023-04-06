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
// Handles the editing of the current frame and allows for changing pixel color and getting pixel color
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
    // gets the current color of a pixel from the canvas based on an event point
    void getPixelColor(QPoint eventPoint);
    // converts a point to the pixel coordinate system for the canvas
    QPoint pointToPixelCoords(QPoint eventPoint);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void repaintSection();
};

#endif // EDITINGSECTION_H
