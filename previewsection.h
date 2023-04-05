/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef PREVIEWSECTION_H
#define PREVIEWSECTION_H

#include <QWidget>
#include <QTime>
#include <QPixmap>
#include <QTimer>
#include <QLabel>

namespace Ui {
class PreviewSection;
}

// QWidget class in the mainwindow that shows a running animation of the
// current state of the sprite.
class PreviewSection : public QWidget
{
    Q_OBJECT

public:
    // Constructs the preview section and starts showing the animation.
    explicit PreviewSection(QWidget *parent = nullptr);

    // Destructs the preview section.
    ~PreviewSection();

    // Shows the next frame in the animation and schedules the next call
    // to showImage() the appropriate number of milliseconds in the future.
    void showImage();

private slots:

    // Opens the fullSizePreview dialog when the user clicks the show full
    // size preview button.
    void onFullSizeClicked();

    // Called when the user changes the FPS slider. Notifies the model of
    // the new FPS value.
    void onFPSSliderChanged(int value);

private:
    Ui::PreviewSection *ui;
    QTimer timer;
    QLabel label;
};

#endif // PREVIEWSECTION_H
