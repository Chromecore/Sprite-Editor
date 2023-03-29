/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "model.h"
#include <QPainter>
#include <qDebug>

Model* Model::instance;

Model::Model()
{
    spriteSize = 32;
    QPixmap startingMap(spriteSize, spriteSize);
    startingMap.fill(Qt::gray);
    pixmaps.push_back(startingMap);
    currentColor = Qt::black;
    currentImageIndex = 0;
}
void Model::init(){
    instance = new Model();
}

void Model::setCurrentPixmap(QPixmap pixmap)
{
    pixmaps.at(currentImageIndex) = pixmap;
}
QPixmap* Model::getPixmap()
{
    return &pixmaps.at(currentImageIndex);
}
vector<QPixmap> Model::getPixmaps()
{
    return pixmaps;
}
void Model::setColor(QColor color)
{
    currentColor = color;
}
QColor Model::getColor()
{
    return currentColor;
}
void Model::setFPS(int fps)
{
    this -> fps = fps;
}
int Model::getFPS()
{
    return fps;
}
bool Model::isOnionSkin()
{
    return onionSkin;
}
void Model::isOnionSkin(bool is)
{
    onionSkin = is;
}
int Model::getSpriteSize()
{
    return spriteSize;
}
void Model::setSpriteSize(int size)
{
    spriteSize = size;
}
void Model::setCurrentIndex(int i)
{
    currentImageIndex = i;
}
void Model::saveFile()
{

}
