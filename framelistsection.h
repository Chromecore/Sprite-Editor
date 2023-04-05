/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef FRAMELISTSECTION_H
#define FRAMELISTSECTION_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "clickablelabel.h"
#include <vector>

using std::vector;

namespace Ui {
class FrameListSection;
}

// QWidget section in the mainwindow that has the list of frames in
// the sprite. Frames can be clicked to select the current frame being
// edited.
class FrameListSection : public QWidget
{
    Q_OBJECT

public:
    // Constructs the FrameListSection with the given parent widget.
    // Fills the list with any pre-existing frames in the model.
    explicit FrameListSection(QWidget *parent = nullptr);

    // Destructor for FrameListSection
    ~FrameListSection();

public slots:
    // Adds a new frame to the end of the list of frames.
    void addFrame();

    // Removes the last frame from the list of frames. Should only be called
    // when there are 2 or more frames in the sprite.
    void removeFrame();

    // Updates the remove frame button and sprite size combo box to prevent
    // the user from removing the last frame or changing the size when more
    // than one frame is in the sprite.
    void updateButtons();

    // Notifies the model of the new sprite size selected by the user.
    // Should only be called if there is only one frame in the list. Replaces
    // the existing frame with a new frame of the selected size.
    void spriteSizeComboBoxIndexChanged(int index);

    // Called when the sprite frame currently being edited is changed. Updates
    // the pixmap inside the frame list to relfect the changes.
    void updateCurPixmap();

    // Replaces any existing frames in the frame list section with the frames
    // in the model's vector. Syncs the model's frames with those in the frame
    // list.
    void setupNewFrameList();

    // Called when a new sprite is loaded from a file. Reflects the accurate
    // sprite size in the sprite size combo box.
    void updateSizeComboBox(int newSize);

private:
    Ui::FrameListSection *ui;
    QScrollArea* scrollArea;
    QVBoxLayout* layout;
    QWidget* widget;
    vector<ClickableLabel*> frames;
};

#endif // FRAMELISTSECTION_H
