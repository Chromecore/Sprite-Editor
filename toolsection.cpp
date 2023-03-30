#include "toolsection.h"
#include "ui_toolsection.h"

ToolSection::ToolSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolSection)
{
    ui->setupUi(this);

    //Button set up
    ui->EyedropButton->setCheckable(true);
    ui->MirrorButton->setCheckable(true);

    //Icon set up
    ui->EyedropButton->setIcon(QIcon(":/Icon/Resources/Eyedropper Icon.png"));
    ui->EyedropButton->setIconSize(QSize(32,32));
    ui->MirrorButton->setIcon(QIcon(":/Icon/Resources/Mirror Icon.png"));
    ui->MirrorButton->setIconSize(QSize(32,32));
}

ToolSection::~ToolSection()
{
    delete ui;
}

void ToolSection::on_EyedropButton_toggled(bool checked)
{
    //Change enumerator to eyedropper. Once clicked, change to pen tool.
}


void ToolSection::on_MirrorButton_toggled(bool checked)
{
    //When drawing, determine if mirror bool is active, determine where to draw
}

