/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef MODEL_H
#define MODEL_H
#include <QImage>

using std::vector;

class Model
{
private:
    vector<QPixmap> pixmaps; // images that make up sprite
    QColor currentColor; // current drawing color
    int fps;          // how fast sprite moves in preview
    bool onionSkin; // overlay previous frame of sprite
    int spriteSize; // size of canvas
    int currentImageIndex = 0; // current index of the image in canvas
public:
    Model();

    Model(const Model& obj) = delete;
    static void init();
    static Model* instance;

    void setCurrentPixmap(QPixmap pixmap);
    QPixmap* getPixmap();
    vector<QPixmap> getPixmaps();
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
