/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "model.h"
#include <QPainter>

#include <QFileDialog>
#include <QMessageBox>

#include <qDebug>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFileDialog>
#include <QMessageBox>

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
    fps = 0;
    previewIndex = 0;
    mirroring = false;
    eyedropActive = false;
    onionSkinActive = false;
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

QPixmap* Model::getPixmap(int index)
{
    if (pixmaps.empty())
        return nullptr;

    return pixmaps.at(index);
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
    return fps + 1;
}

int Model::getSpriteSize()
{
    return spriteSize;
}

// Changes the size of the sprite canvas.
void Model::setSpriteSize(int size)
{
    spriteSize = size;
//    QPixmap* newcurrentPixmap = new QPixmap(spriteSize, spriteSize);
//    newcurrentPixmap->fill(Qt::transparent);

    if (pixmaps.size() == 1) {
        QPixmap* oldPixmap = pixmaps.at(pixmaps.size() - 1);
        pixmaps.pop_back();
        delete oldPixmap;
    }

    addFrame();
//    pixmaps.push_back(newcurrentPixmap);
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

void Model::saveFile(QString fileLocation)
{
    qDebug() << "Save File";
    QJsonObject spriteObject;
    spriteObject.insert("height", QJsonValue::fromVariant(spriteSize));
    spriteObject.insert("width", QJsonValue::fromVariant(spriteSize));
    spriteObject.insert("numberOfFrames", QJsonValue::fromVariant(pixmaps.size()));

    QJsonObject framesObject;

    for (int i = 0; i < (int)pixmaps.size(); i++) {
        QJsonArray frame;
        QPixmap* pixmap = pixmaps.at(i);
        QImage image = pixmap->toImage();

        for (int row = 0; row < spriteSize; row++) {
            QJsonArray rowArray;

            for (int col = 0; col < spriteSize; col++) {
                QColor color = image.pixelColor(col, row);

                QJsonArray pointRGBA;
                pointRGBA.push_back(QJsonValue::fromVariant(color.red()));
                pointRGBA.push_back(QJsonValue::fromVariant(color.green()));
                pointRGBA.push_back(QJsonValue::fromVariant(color.blue()));
                pointRGBA.push_back(QJsonValue::fromVariant(color.alpha()));

                rowArray.push_back(QJsonValue::fromVariant(pointRGBA));
            }

            frame.push_back(QJsonValue::fromVariant(rowArray));
        }

        framesObject.insert(tr("frame%0").arg(i), frame);
    }

    spriteObject.insert("frames", framesObject);

    QJsonDocument doc(spriteObject);
//    qDebug() << doc.toJson();


    QString fileName = fileLocation;
    QFile jsonFile(fileName);
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson());

}
void Model::loadFile()
{
    qDebug() << "Load File";


//    QString filename = QFileDialog::getOpenFileName(nullptr, tr("open file"), QString(), tr(".ssp"), nullptr, QFileDialog::Options());
    QString filepath = QFileDialog::getOpenFileName();
    qDebug() << filepath;

    if (!filepath.endsWith(tr(".ssp"))) {
        emit invalidFile();
        return;
    }

    QFile fileObj(filepath);

    if (!fileObj.open(QIODevice::ReadOnly)) {
        emit invalidFile();
        return;
    }

    QTextStream fileText(&fileObj);
    QString jsonString = fileText.readAll();
    fileObj.close();
    QByteArray jsonBytes = jsonString.toLocal8Bit();

    auto jsonDoc = QJsonDocument::fromJson(jsonBytes);

    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        emit invalidFile();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    if (jsonObj.isEmpty()) {
        emit invalidFile();
        return;
    }

    QVariantMap map = jsonObj.toVariantMap();

    if (!map.contains(tr("width")) || !map.contains(tr("height")) ||
        !map.contains(tr("numberOfFrames")) || !map.contains(tr("frames"))) {
        emit invalidFile();
        return;
    }

    QVariant widthVar = map.value(tr("width"));
    int width = widthVar.toInt();
    QVariant heightVar = map.value(tr("height"));
    int height = heightVar.toInt();
    QVariant numFramesVar = map.value(tr("numberOfFrames"));
    int numFrames = numFramesVar.toInt();
    QVariant framesVar = map.value(tr("frames"));
    QJsonObject framesObj = framesVar.toJsonObject();
    QVariantMap framesMap = framesObj.toVariantMap();

    if (width != height || numFrames <= 0) {
        emit invalidFile();
        return;
    }

    // empty out the pixmaps vector
    for (int i = 0; i < (int)pixmaps.size(); i++) {
        removeFrame();
    }

    setSpriteSize(width);

    for (int i = 0; i < numFrames; i++) {
        if (!framesMap.contains(tr("frame%0").arg(i))) {
            emit invalidFile();

            if (pixmaps.empty()) {
                addFrame();
                emit newFrameList();
            }
            return;
        }

        if (i > 0) { // First frame is already added when setSpriteSize is called
            addFrame();
        }

        QVariant frameArrayVar = framesMap.value(tr("frame%0").arg(i));
        QJsonArray frameArray = frameArrayVar.toJsonArray();
        QPixmap* pixmap = pixmaps.at(i);

        for (int row = 0; row < height; row++) {
            QJsonArray rowArray = frameArray.at(row).toArray();

            for (int col = 0; col < width; col++) {
                QJsonArray pointArray = rowArray.at(col).toArray();
                QColor color;
                color.setRed(pointArray.at(0).toInt());
                color.setGreen(pointArray.at(1).toInt());
                color.setBlue(pointArray.at(2).toInt());
                color.setAlpha(pointArray.at(3).toInt());

                QImage temp = pixmap->toImage();
                temp.setPixelColor(col, row, color);
                pixmap->convertFromImage(temp);
            }
        }
    }

    emit newFrameList();
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

    emit frameRemoved();
    return true;
}

QPixmap* Model::getNextPreview()
{
    previewIndex++;
    previewIndex = previewIndex % pixmaps.size();
    if (pixmaps.empty())
        return nullptr;
    return pixmaps[previewIndex];
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

bool Model::getOnionSkin(){
    return onionSkinActive;
}

void Model::toggleOnionSkin(){
    onionSkinActive = !onionSkinActive;
    emit onionChanged();
}
