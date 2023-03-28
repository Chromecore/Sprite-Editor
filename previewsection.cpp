#include "previewsection.h"
#include "ui_previewsection.h"

PreviewSection::PreviewSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreviewSection)
{
    ui->setupUi(this);
}

PreviewSection::~PreviewSection()
{
    delete ui;
}
