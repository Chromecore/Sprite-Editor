/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "fullsizepreview.h"
#include "ui_fullsizepreview.h"
#include "model.h"

FullSizePreview::FullSizePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FullSizePreview)
{
    ui->setupUi(this);

    frameIndex = 0;
    timer.setTimerType(Qt::PreciseTimer);

    this->setWindowTitle(tr("Full Size Animation"));

    showImage();
    this->exec();
}

FullSizePreview::~FullSizePreview()
{
    delete ui;
}

void FullSizePreview::showImage() {
    int fps = Model::instance->getFPS();
    vector<QPixmap*> pixmaps = Model::instance->getPixmaps();

    QPixmap* pixmap = pixmaps.at(frameIndex++);
    frameIndex = frameIndex % pixmaps.size();

    ui->label->setPixmap(pixmap->scaled(450, 450));
    timer.singleShot(1000/fps, this, &FullSizePreview::showImage);

    repaint();
}
