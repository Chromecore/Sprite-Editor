#include "model.h"

Model::Model()
{



}


void Model::setImage(QImage image)
{
    images.at(currentImageIndex) = image;
}
QImage Model::getImage()
{
    return images.at(currentImageIndex);
}
vector<QImage> Model::getImages()
{
    return images;
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
