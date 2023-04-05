/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "previewsection.h"
#include "ui_previewsection.h"
#include <QTimer>
#include <QDebug>
#include "model.h"
#include <QPainter>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include "fullsizepreview.h"

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,
            &QSlider::sliderMoved,
            this,
            &PreviewSection::onFPSSliderChanged);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &PreviewSection::onFullSizeClicked);

    label.setParent(this);
    label.setGeometry(0, 0, 150, 150);
    label.setFrameStyle(1);

    timer.setTimerType(Qt::PreciseTimer);

    showImage();
}

void PreviewSection::showImage()
{
    int fps = Model::instance -> getFPS()  ;
    QPixmap* pixmap = Model::instance -> getNextPreview();
    label.setPixmap(pixmap -> scaled(150, 150));
    timer.singleShot(1000/fps, this, &PreviewSection::showImage);
}

PreviewSection::~PreviewSection()
{
    delete ui;
}

void PreviewSection::onFullSizeClicked() {
    FullSizePreview fullSizePreview(this->parentWidget());
}

void PreviewSection::onFPSSliderChanged(int value) {
    Model::instance->setFPS(value);
}
