#include "previewsection.h"
#include "ui_previewsection.h"
#include <QTimer>
#include <QDebug>
#include "model.h"
#include <QLabel>

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

//    connect(Model::instance,
//                    &Model::updatedCurrentPixmap,
//                    this,
//                    &PreviewSection::test);

    connect(ui->horizontalSlider,
            &QSlider::sliderMoved,
            this,
            &PreviewSection::onFPSSliderChanged);

    label.setParent(this);
    label.setGeometry(0, 0, 150, 150);
    label.setFrameStyle(1);

    timer.setTimerType(Qt::PreciseTimer);

    showImage();
}

void PreviewSection::showImage()
{
    int fps = Model::instance -> getFPS() + 1;
    QPixmap pixmap = Model::instance -> getNextPreview();

    label.setPixmap(pixmap.scaled(150, 150));
    timer.singleShot(1000/fps, this, &PreviewSection::showImage);
}

PreviewSection::~PreviewSection()
{
    delete ui;
}

void PreviewSection::on_horizontalSlider_valueChanged(int value)
{
    Model::instance->setFPS(value);
}

void PreviewSection::onFullSizeClicked() {

}

void PreviewSection::onFPSSliderChanged(int value) {
    Model::instance->setFPS(value);
}
