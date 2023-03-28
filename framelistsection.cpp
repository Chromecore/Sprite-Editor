#include "framelistsection.h"
#include "ui_framelistsection.h"

FrameListSection::FrameListSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameListSection)
{
    ui->setupUi(this);
}

FrameListSection::~FrameListSection()
{
    delete ui;
}
