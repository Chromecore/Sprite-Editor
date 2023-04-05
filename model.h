/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef MODEL_H
#define MODEL_H
#include <QObject>
#include <QImage>

using std::vector;

class Model : public QObject
{
    Q_OBJECT

private:
    vector<QPixmap*> pixmaps; // images that make up sprite
    QColor currentColor; // current drawing color
    QColor storedColor; // last color stored internally to be referenced as needed
    int fps;          // how fast sprite moves in preview
    int spriteSize; // size of canvas
    int currentImageIndex = 0; // current index of the image in canvas
    int previewIndex;
    bool mirroring; // If pen strokes are mirrored
    bool eyedropActive; // If eye drop tool is being used
    bool onionSkinActive;

public:
    explicit Model(QObject *parent = nullptr);

    Model(const Model& obj) = delete;
    static void init();
    static Model* instance;

    void setCurrentPixmap(QPixmap* pixmap);
    QPixmap* getPixmap();
    QPixmap* getPixmap(int index);
    std::vector<QPixmap*>& getPixmaps();
    void setColor(QColor color);
    void setStoredColor(QColor color);
    QColor getColor();
    QColor getStoredColor();
    void setFPS(int fps);
    int getFPS();
    int getSpriteSize();
    bool getMirroring();
    bool getEyedropActive();
    void setSpriteSize(int size);
    void setCurrentIndex(int i);
    int getCurrentIndex();
    void setMirroring(bool is);
    void setEyedropActive(bool is);
    void saveFile(QString fileLocation);
    void loadFile();
    void addFrame();
    bool removeFrame();

    QPixmap* getNextPreview();
    void toggleOnionSkin();
    bool getOnionSkin();
signals:
    void updatedCurrentPixmap();
    void eyedropToolSetButtonPressed(bool pressed);
    void eyedropToolSetNewColor(QString newColor);
    void currentIndexChanged();
    void sizeChanged();
    void onionChanged();
    void invalidFile();
    void frameRemoved();
    void newFrameList();
    void newSpriteSize(int newSize);
};

#endif // MODEL_H
