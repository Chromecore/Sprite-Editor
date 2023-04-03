/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "model.h"
#include <QPainter>
#include <qDebug>

Model* Model::instance;

Model::Model(QObject *parent) : QObject(parent)
{
    spriteSize = 32;
    QPixmap* startingMap = new QPixmap(spriteSize, spriteSize);
    startingMap->fill(Qt::transparent);
    pixmaps.push_back(startingMap);
    currentColor = Qt::black;
    storedColor = currentColor;
    currentImageIndex = 0;
    previewIndex = 0;
    mirroring = false;
    eyedropActive = false;

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
    if (pixmaps.empty())
        return nullptr;

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

void Model::setStoredColor(QColor color)
{
    storedColor = color;
}

QColor Model::getStoredColor()
{
    return storedColor;
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

// Changes the size of the sprite canvas. Must only be called
// if there is one frame
void Model::setSpriteSize(int size)
{
    spriteSize = size;
    QPixmap* newcurrentPixmap = new QPixmap(spriteSize, spriteSize);
    newcurrentPixmap->fill(Qt::transparent);

    QPixmap* oldPixmap = pixmaps.at(pixmaps.size() - 1);
    pixmaps.pop_back();
    delete oldPixmap;

    pixmaps.push_back(newcurrentPixmap);
    emit sizeChanged();
}

void Model::setCurrentIndex(int i)
{
    currentImageIndex = i;

    emit currentIndexChanged();
}

int Model::getCurrentIndex() {
    return currentImageIndex;
}

void Model::saveFile()
{
    qDebug() << "Save File";
}
void Model::loadFile()
{
    qDebug() << "Load File";
}

void Model::addFrame()
{
    QPixmap* newFrame = new QPixmap(spriteSize, spriteSize);
    newFrame->fill(Qt::transparent);
    pixmaps.push_back(newFrame);

    setCurrentIndex(pixmaps.size() - 1);
}

// Returns true if a frame was removed, false otherwise
bool Model::removeFrame()
{
    if (pixmaps.empty()) {
        return false;
    }

    QPixmap* removed = pixmaps.at(pixmaps.size() - 1);
    pixmaps.pop_back();
    delete removed;

    if (currentImageIndex == (int)pixmaps.size()) {
        setCurrentIndex(pixmaps.size() - 1);
    }

    return true;
}

QPixmap Model::getNextPreview()
{
    previewIndex++;
    previewIndex = previewIndex % pixmaps.size();
    return *pixmaps[previewIndex];
}


bool Model::getMirroring()
{
    return mirroring;
}

void Model::setMirroring(bool is)
{
    mirroring = is;
}

bool Model::getEyedropActive()
{
    return eyedropActive;
}

void Model::setEyedropActive(bool is)
{
    eyedropActive = is;
}

