#include "previewsection.h"
#include "ui_previewsection.h"
#include <QTimer>
#include <QDebug>
#include "model.h"

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

//    connect(Model::instance,
//                    &Model::updatedCurrentPixmap,
//                    this,
//                    &PreviewSection::test);

    int fps = Model::instance -> getFPS() + 1;
    QTimer::singleShot(1000/fps, this, &PreviewSection::showImage);
}

void PreviewSection::showImage()
{
    int fps = Model::instance -> getFPS() +1 ;
    QPixmap pixmap = Model::instance -> getNextPreview();
    ui->myLabel->setPixmap(pixmap);
    ui->myLabel->setMask(pixmap.mask());
    QTimer::singleShot(1000/fps, this, &PreviewSection::showImage);
}

PreviewSection::~PreviewSection()
{
    delete ui;
}

void PreviewSection::on_horizontalSlider_valueChanged(int value)
{
    Model::instance->setFPS(value);
}

