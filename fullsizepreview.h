/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef FULLSIZEPREVIEW_H
#define FULLSIZEPREVIEW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class FullSizePreview;
}

// QDialog that opens when user clicks show full size preview button in
// the preview section. Includes a label showing the animation at full
// size of 450 by 450.
class FullSizePreview : public QDialog
{
    Q_OBJECT

public:
    // Constructs the full size preview dialog. Grabs focus from the
    // mainwindow and starts the animation.
    explicit FullSizePreview(QWidget *parent = nullptr);

    // Destructs the full size preview.
    ~FullSizePreview();

private:
    Ui::FullSizePreview *ui;
    int frameIndex;
    QTimer timer;

    // Shows the next frame in the animation and schedules the next call
    // to showImage() the appropriate number of milliseconds in the future.
    void showImage();
};

#endif // FULLSIZEPREVIEW_H
