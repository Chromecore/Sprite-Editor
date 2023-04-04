#include "previewsection.h"
#include "ui_previewsection.h"
#include <QTimer>
#include <QDebug>
#include <QPainter>


PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

//    connect(Model::instance,
//                    &Model::updatedCurrentPixmap,
//                    this,
//                    &PreviewSection::test);

    int fps = Model::instance -> getFPS() ;
    QTimer::singleShot(1000/fps, this, &PreviewSection::showImage);
}

void PreviewSection::showImage()
{

    int fps = Model::instance -> getFPS()  ;
    //QPixmap pixmap = Model::instance -> getNextPreview();
    QPainter painter(this);
    QPixmap* pixmap = Model::instance->getNextPreview();

    if(pixmap)
        painter.drawTiledPixmap(0, 0,150,150, *pixmap);
    QTimer timer;
    timer.setTimerType(Qt::PreciseTimer);
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

