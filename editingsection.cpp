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
#include "toolsection.h"

EditingSection::EditingSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingSection)
{
    ui->setupUi(this);
}

EditingSection::~EditingSection()
{
    delete ui;
}

void EditingSection::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QPixmap* currentPixmap = Model::instance->getPixmap();
    if(currentPixmap == nullptr) return;

    painter.drawPixmap(0, 0, currentPixmap->scaled(size().width(), size().height()));
}

void EditingSection::mousePressEvent(QMouseEvent* event) {
    mousePressed = true;
    // colors the first pixel before the mouse stars moving
    if (Model::instance->getEyedropActive()) {
        getPixelColor(event->pos());
    }
    else {
        colorPixel(event->pos());

        // Change color to transparent to erase with right click
        if(event->button()==Qt::RightButton) Model::instance->setColor(Qt::transparent);
        else Model::instance->setColor(Model::instance->getStoredColor());
    }

}

void EditingSection::mouseReleaseEvent(QMouseEvent*){
    mousePressed = false;
}

void EditingSection::mouseMoveEvent(QMouseEvent *event){
    if(!mousePressed) return;
    if (!Model::instance->getEyedropActive()) colorPixel(event->pos());
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
    QPixmap* currentPixmap = Model::instance->getPixmap();
    if(currentPixmap == nullptr) return;
    QPainter painter(currentPixmap);

    // erase if the color should be transparent
    if(Model::instance->getColor() == Qt::transparent){
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
    }
    painter.setPen(Model::instance->getColor());
    painter.drawPoint(x, y);
    if (Model::instance->getMirroring()){
        // essentially, gets opposite coord of X axis by subtracting current x position from sprite size.
        painter.drawPoint(Model::instance->getSpriteSize()-x, y);
    }
    emit Model::instance->updatedCurrentPixmap();

    repaint();
}

void EditingSection::getPixelColor(QPoint eventPoint)
{
    // like before, find the x and y pixel coordinates of the point
    double pixelWidth = this->size().width() / Model::instance->getSpriteSize();
    double pixelHeight = this->size().height() / Model::instance->getSpriteSize();
    int x = (eventPoint.x()) / pixelWidth;
    int y = (eventPoint.y()) / pixelHeight;

    bool withinImageBounds = x < Model::instance->getSpriteSize() && x >= 0 && y < Model::instance->getSpriteSize() && y >= 0;
    if(!withinImageBounds) return;

    // get the model's pixmap, convert it to an image
    QPixmap* currentPixmap = Model::instance->getPixmap();
    if(currentPixmap == nullptr) return;
    QImage currentImage = currentPixmap->toImage();

    QColor extractedColor = currentImage.pixel(x,y);
    Model::instance->setColor(extractedColor);
    Model::instance->setStoredColor(extractedColor);
    emit Model::instance->eyeDropToolUsed();

}
