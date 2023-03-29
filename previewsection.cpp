#include "previewsection.h"
#include "ui_previewsection.h"

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);

//    while(true)
//    {
//        for (QPixmap& image : Model::instance->getPixmaps())
//        {
//            if(delay(1))
//            {
//                ui->myLabel->setPixmap(image);
//            }
//        }
//    }
}

bool PreviewSection::delay(int sec)
{
    QTime dieTime = QTime::currentTime().addSecs(sec / Model::instance->getFPS());

    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    return true;
}

PreviewSection::~PreviewSection()
{
    delete ui;
}

void PreviewSection::on_horizontalSlider_valueChanged(int value)
{
    Model::instance->setFPS(value);
}

