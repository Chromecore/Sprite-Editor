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

// Holds all the data and functions for the sprite editor
class Model : public QObject
{
    Q_OBJECT

private:
    // images that make up sprite
    vector<QPixmap*> pixmaps;
    // current drawing color
    QColor currentColor;
    // last color stored internally to be referenced as needed
    QColor storedColor;
    // how fast sprite moves in preview (frames per second)
    int fps;
    // size of canvas
    int spriteSize;
    // current index of the image in canvas
    int currentImageIndex = 0;
    int previewIndex;
    // If pen strokes are mirrored
    bool mirroring;
    // If eye drop tool is being used
    bool eyedropActive;
    bool onionSkinActive;

public:
    explicit Model(QObject *parent = nullptr);

    Model(const Model& obj) = delete;
    //set up instance
    static void init();
    static Model* instance;

    //modifies vector of pixmap(s)
    void setCurrentPixmap(QPixmap* pixmap);
    //gets pixmap at currentImageIndex
    QPixmap* getPixmap();
    //gets pixmap at index
    QPixmap* getPixmap(int index);
    //gets all pixmaps of sprite
    std::vector<QPixmap*>& getPixmaps();

    //sets currentColor
    void setColor(QColor color);
    //sets storedColor
    void setStoredColor(QColor color);
    //returns currentColor
    QColor getColor();
    //return storedColor
    QColor getStoredColor();

    // sets fps (frames pre second)
    void setFPS(int fps);
    // returns fps (frames pre second)
    int getFPS();

    //returns spriteSize
    int getSpriteSize();
    //sets spriteSize and reformats sprite pixal size if there is only one pixmap
    void setSpriteSize(int size);

    //set current pixmap index
    void setCurrentIndex(int i);
    //returns currentIndex
    int getCurrentIndex();

    //saves a JSON file based on sprite
    void saveFile(QString fileLocation);
    //loads sprite from a JSON
    void loadFile();

    //adds frame/pixmap to sprite
    void addFrame();
    //removes frame/pixmap to sprite
    bool removeFrame();

    //gets next pixmap to be displayed in preview
    QPixmap* getNextPreview();

    //tells if currently mirroring
    bool getMirroring();
    //turns mirroring on and off
    void setMirroring(bool is);

    //tells if currently using eyedropper
    bool getEyedropActive();
    //turns on and off eye dropper
    void setEyedropActive(bool is);

    //turns on and off onionSkin
    void toggleOnionSkin();
    //returns if onionskin is currently on
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
