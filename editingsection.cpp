#include "editingsection.h"
#include "ui_editingsection.h"

EditingSection::EditingSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditingSection)
{
    ui->setupUi(this);
}

EditingSection::~EditingSection()
{
    delete ui;
}
