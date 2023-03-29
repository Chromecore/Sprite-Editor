#ifndef MODEL_H
#define MODEL_H
#include <QImage>
using std::vector;

class Model
{
private:
    static vector<QImage> images; //images that make up sprite

    static QColor currentColor; // current drawing color
    static int fps;          // how fast sprite moves in preview
    static bool onionSkin; //form of shadow to look at previos portions of sprite
    static int spriteSize; //size of canvas
    static int currentImageIndex; // current index of the image in canvas
public:
    Model();

    void setImage(QImage image);
    QImage getImage();
    vector<QImage> getImages();
    void setColor(QColor color);
    QColor getColor();
    void setFPS(int fps);
    int getFPS();
    bool isOnionSkin();
    void isOnionSkin(bool is);
    int getSpriteSize();
    void setSpriteSize(int size);
    void setCurrentIndex(int i);
    void saveFile();

};

#endif // MODEL_H
