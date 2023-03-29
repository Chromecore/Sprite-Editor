/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "editingsection.h"
#include "ui_editingsection.h"
#include <QMouseEvent>
#include <QPainter>
#include "model.h"

EditingSection::EditingSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingSection)
{
    ui->setupUi(this);
    // create the pixmap
    //QPixmap pixmap = QPixmap(imageSize, imageSize);
    //pixmap.fill(Qt::gray);
    //Model::getInstance()->setCurrentPixmap(pixmap);
}

EditingSection::~EditingSection()
{
    delete ui;
}

void EditingSection::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap* currentPixmap = Model::instance->getPixmap();
    painter.drawPixmap(0, 0, currentPixmap->scaled(size().width(), size().height()));
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
    double pixelWidth = this->size().width() / Model::instance->getSpriteSize();
    double pixelHeight = this->size().height() / Model::instance->getSpriteSize();
    int x = (eventPoint.x()) / pixelWidth;
    int y = (eventPoint.y()) / pixelHeight;

    bool withinImageBounds = x < Model::instance->getSpriteSize() && x >= 0 && y < Model::instance->getSpriteSize() && y >= 0;
    if(!withinImageBounds) return;

    // update the pixel color using a painter
    QPainter painter(Model::instance->getPixmap());
    painter.setPen(Model::instance->getColor());
    painter.drawPoint(x, y);

    repaint();
}

