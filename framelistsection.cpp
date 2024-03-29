/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#include "framelistsection.h"
#include "ui_framelistsection.h"
#include "QVBoxLayout"
#include "QPushButton"
#include <QScrollArea>
#include "QLabel"
#include "QSize"
#include <vector>
#include "model.h"
#include "clickablelabel.h"

using std::vector;

FrameListSection::FrameListSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameListSection)
{
    ui->setupUi(this);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    QSize sectionSize(this->size());
    sectionSize.setHeight(sectionSize.height() - 100);
    scrollArea->setFixedSize(sectionSize);

    widget = new QWidget;
    scrollArea->setWidget(widget);

    // set up layout
    layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop);

    ui->removeFrameButton->setDisabled(true);
    setupNewFrameList();

    // connect calls:
    connect(ui->addFrameButton,
            &QPushButton::clicked,
            this,
            &FrameListSection::addFrame);

    connect(ui->removeFrameButton,
            &QPushButton::clicked,
            this,
            &FrameListSection::removeFrame);

    connect(ui->spriteSizeComboBox,
            &QComboBox::currentIndexChanged,
            this,
            &FrameListSection::spriteSizeComboBoxIndexChanged);

    connect(Model::instance,
            &Model::updatedCurrentPixmap,
            this,
            &FrameListSection::updateCurPixmap);

    connect(Model::instance,
            &Model::frameRemoved,
            this,
            &FrameListSection::updateButtons);

    connect(Model::instance,
            &Model::newFrameList,
            this,
            &FrameListSection::setupNewFrameList);

    connect(Model::instance,
            &Model::newSpriteSize,
            this,
            &FrameListSection::updateSizeComboBox);
}

FrameListSection::~FrameListSection()
{
    delete ui;
}

void FrameListSection::addFrame() {

    Model::instance->addFrame();

    if (frames.size() == 0) {
        switch (ui->spriteSizeComboBox->currentIndex()) {
            case 0:
                Model::instance->setSpriteSize(32);
                break;
            case 1:
                Model::instance->setSpriteSize(16);
                break;
            case 2:
                Model::instance->setSpriteSize(8);
                break;
            case 3:
                Model::instance->setSpriteSize(4);
                break;
            default:
                Model::instance->setSpriteSize(32);
                break;
        }
    }

    vector<QPixmap*> pixmaps = Model::instance->getPixmaps();
    ClickableLabel* clickLabel = new ClickableLabel;
    clickLabel->setMinimumSize(100, 100);
    clickLabel->setFixedSize(120, 120);
    clickLabel->setPixmap(pixmaps.at(pixmaps.size() - 1)->scaled(120, 120));
    clickLabel->setLineWidth(1);
    clickLabel->setFrameStyle(1);

    layout->addWidget(clickLabel);
    frames.push_back(clickLabel);
    clickLabel->index = frames.size() - 1;

    updateButtons();
}

void FrameListSection::removeFrame() {
    bool removed = Model::instance->removeFrame();

    if (!removed)
        return;

    ClickableLabel* frame = frames.at(frames.size() - 1);
    layout->removeWidget(frame);
    frames.pop_back();
    delete frame;

    updateButtons();
}

void FrameListSection::spriteSizeComboBoxIndexChanged(int index)
{
    switch (index) {
        case 0:
            Model::instance->setSpriteSize(32);
            break;
        case 1:
            Model::instance->setSpriteSize(16);
            break;
        case 2:
            Model::instance->setSpriteSize(8);
            break;
        case 3:
            Model::instance->setSpriteSize(4);
            break;
        default:
            Model::instance->setSpriteSize(32);
            break;
    }

    ClickableLabel* frame = frames.at(frames.size() - 1);
    layout->removeWidget(frame);
    frames.pop_back();
    delete frame;

    vector<QPixmap*> pixmaps = Model::instance->getPixmaps();
    ClickableLabel* clickLabel = new ClickableLabel;
    clickLabel->setMinimumSize(100, 100);
    clickLabel->setFixedSize(120, 120);
    clickLabel->setPixmap(pixmaps.at(pixmaps.size() - 1)->scaled(120, 120));
    clickLabel->setLineWidth(1);
    clickLabel->setFrameStyle(1);

    layout->addWidget(clickLabel);
    frames.push_back(clickLabel);
    clickLabel->index = frames.size() - 1;
}

void FrameListSection::updateCurPixmap() {
    int index = Model::instance->getCurrentIndex();
    frames.at(index)->setPixmap(Model::instance->getPixmap()->scaled(120, 120));
}

void FrameListSection::updateButtons() {
    if (frames.size() <= 1) {
        ui->removeFrameButton->setDisabled(true);
        ui->spriteSizeComboBox->setEnabled(true);
    }
    else {
        ui->removeFrameButton->setEnabled(true);
        ui->spriteSizeComboBox->setDisabled(true);
    }
}

void FrameListSection::setupNewFrameList() {

    for (int i = (int)frames.size() - 1; i >= 0; i--) {
        ClickableLabel* frame = frames.at(i);
        layout->removeWidget(frame);
        frames.pop_back();
        delete frame;
    }

    vector<QPixmap*>& pixmaps = Model::instance->getPixmaps();

    for (QPixmap* pixmap : pixmaps) {
        ClickableLabel* clickLabel = new ClickableLabel;
        clickLabel->setMinimumSize(100, 100);
        clickLabel->setFixedSize(120, 120);
        clickLabel->setPixmap(pixmap->scaled(120, 120));
        clickLabel->setLineWidth(1);
        clickLabel->setFrameStyle(1);

        layout->addWidget(clickLabel);
        frames.push_back(clickLabel);
        clickLabel->index = frames.size() - 1;
    }

    updateButtons();
}

void FrameListSection::updateSizeComboBox(int newSize) {
    switch (newSize) {
        case 32:
            ui->spriteSizeComboBox->setCurrentIndex(0);
            break;
        case 16:
            ui->spriteSizeComboBox->setCurrentIndex(1);
            break;
        case 8:
            ui->spriteSizeComboBox->setCurrentIndex(2);
            break;
        case 4:
            ui->spriteSizeComboBox->setCurrentIndex(3);
            break;
        default:
            ui->spriteSizeComboBox->setCurrentIndex(0);
            break;
    }
}

