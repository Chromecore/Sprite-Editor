#include "toolsection.h"
#include "ui_toolsection.h"

ToolSection::ToolSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolSection)
{
    ui->setupUi(this);
}

ToolSection::~ToolSection()
{
    delete ui;
}
