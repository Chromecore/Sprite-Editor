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
    QPixmap* startingMap = new QPixmap(spriteSize, spriteSize);
    startingMap->fill(Qt::gray);
//    startingMap->fill(Qt::transparent);
    pixmaps.push_back(startingMap);
    currentColor = Qt::black;
    currentImageIndex = 0;
    previewIndex = 0;
}

void Model::init(){
    instance = new Model();
}

void Model::setCurrentPixmap(QPixmap* pixmap)
{
    pixmaps.at(currentImageIndex) = pixmap;
}

QPixmap* Model::getPixmap()
{
    return pixmaps.at(currentImageIndex);
}

vector<QPixmap*>& Model::getPixmaps()
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
    this->fps = fps;
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
    QPixmap* newcurrentPixmap = new QPixmap(spriteSize, spriteSize);
    newcurrentPixmap->fill(Qt::gray);
    pixmaps.push_back(newcurrentPixmap);
    delete (getPixmap());
    setCurrentPixmap(newcurrentPixmap);
}

void Model::setCurrentIndex(int i)
{
    currentImageIndex = i;
}

void Model::saveFile()
{

}

void Model::addFrame()
{
    QPixmap* newFrame = new QPixmap(spriteSize, spriteSize);
    newFrame->fill(Qt::gray);
    pixmaps.push_back(newFrame);
}

// Returns true if a frame was removed, false otherwise
bool Model::removeFrame()
{
    if ((int)pixmaps.size() == 0) {
        return false;
    }

    pixmaps.pop_back();
    return true;
}

QPixmap Model::getNextPreview()
{
    previewIndex++;
    previewIndex = previewIndex % pixmaps.size();
    return *pixmaps[previewIndex];
}
