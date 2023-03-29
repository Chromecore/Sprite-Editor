/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "editingsection.h"
#include "ui_editingsection.h"
#include <QMouseEvent>
#include <QPainter>

EditingSection::EditingSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingSection)
{
    ui->setupUi(this);
    // create the pixmap
    pixmap = QPixmap(imageSize, imageSize);
    pixmap.fill(Qt::gray);
}

EditingSection::~EditingSection()
{
    delete ui;
}

void EditingSection::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap.scaled(size().width(), size().height()));
}

void EditingSection::mousePressEvent(QMouseEvent* event) {
    mousePressed = true;
    // colors the first pixel before the mouse stars moving
    colorPixel(event->pos());
}

void EditingSection::mouseReleaseEvent(QMouseEvent*){
    mousePressed = false;
}

void EditingSection::mouseMoveEvent(QMouseEvent *event){
    if(!mousePressed) return;
    colorPixel(event->pos());
}

void EditingSection::colorPixel(QPoint eventPoint){
    // find the x and y pixel coordinates of the point
    double pixelWidth = this->size().width() / imageSize;
    double pixelHeight = this->size().height() / imageSize;
    int x = (eventPoint.x()) / pixelWidth;
    int y = (eventPoint.y()) / pixelHeight;

    bool withinImageBounds = x < imageSize && x >= 0 && y < imageSize && y >= 0;
    if(!withinImageBounds) return;

    // update the pixel color using a painter
    QPainter painter(&pixmap);
    painter.setPen(currentColor);
    painter.drawPoint(x, y);

    repaint();
}

