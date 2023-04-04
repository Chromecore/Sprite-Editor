#include "toolsection.h"
#include "ui_toolsection.h"
#include "model.h"
#include <QColorDialog>

ToolSection::ToolSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolSection)
{
    ui->setupUi(this);

    //Button set up
    ui->EyedropButton->setCheckable(true);
    ui->MirrorButton->setCheckable(true);
    ui->OnionSkinButton->setCheckable(true);

    //Icon set up
    ui->EyedropButton->setIcon(QIcon(":/Icon/Resources/Eyedropper Icon.png"));
    ui->EyedropButton->setIconSize(QSize(32,32));
    ui->MirrorButton->setIcon(QIcon(":/Icon/Resources/Mirror Icon.png"));
    ui->MirrorButton->setIconSize(QSize(32,32));
    ui->OnionSkinButton->setIcon(QIcon(":/Icon/Resources/Onion Icon.png"));
    ui->OnionSkinButton->setIconSize(QSize(32,32));

    //ColorPickerDefaultSetUp
    QColor col = Model::instance->getColor();
    if(col.isValid()) {
        QString qss = QString("background-color: %1").arg(col.name());
        ui->ColorButton->setStyleSheet(qss);
    }
    ui->ColorButton->update();

    connect(Model::instance,
        &Model::eyedropToolSetButtonPressed,
        ui->EyedropButton,
        &QPushButton::setChecked
        );

    connect(Model::instance,
        &Model::eyedropToolSetNewColor,
        ui->ColorButton,
        &QPushButton::setStyleSheet
        );

    connect(ui->OnionSkinButton,
        &QPushButton::clicked,
        Model::instance,
        &Model::toggleOnionSkin
        );
}


ToolSection::~ToolSection()
{
    delete ui;
}

void ToolSection::on_EyedropButton_toggled(bool checked)
{
    Model::instance->setEyedropActive(checked);
    ui->ColorButton->setEnabled(!checked);
}


void ToolSection::on_MirrorButton_toggled(bool checked)
{
    Model::instance->setMirroring(checked);
}


void ToolSection::on_ColorButton_clicked()
{
    QColor newColor = QColorDialog::getColor(Qt::white, this);
    if(newColor.isValid()) {
        Model::instance->setColor(newColor);
        Model::instance->setStoredColor(newColor);
        QString qss = QString("background-color: %1").arg(newColor.name());
        ui->ColorButton->setStyleSheet(qss);
    }
}
