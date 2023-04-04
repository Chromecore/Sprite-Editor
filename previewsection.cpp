#include "previewsection.h"
#include "ui_previewsection.h"
#include <QTimer>
#include <QDebug>
#include "model.h"
#include "clickablelabel.h"

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

//    connect(Model::instance,
//                    &Model::updatedCurrentPixmap,
//                    this,
//                    &PreviewSection::test);
    clickLabel.setParent(this);
    clickLabel.setGeometry(0, 0, 150, 150);
    clickLabel.setFrameStyle(1);

    timer.setTimerType(Qt::PreciseTimer);

//    int fps = Model::instance -> getFPS() + 1;
//    timer.singleShot(1000/fps, this, &PreviewSection::showImage);
    showImage();
}

void PreviewSection::showImage()
{
    int fps = Model::instance -> getFPS() + 1;
    QPixmap pixmap = Model::instance -> getNextPreview();

    clickLabel.setPixmap(pixmap.scaled(150, 150));
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

