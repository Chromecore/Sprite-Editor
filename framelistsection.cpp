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
    sectionSize.setHeight(sectionSize.height() - 90);
    scrollArea->setFixedSize(sectionSize);

    widget = new QWidget;
    scrollArea->setWidget(widget);

    // set up layout
    layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop);

    ui->removeFrameButton->setDisabled(true);

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
    }

    if (frames.empty()) {
        noFramesLabel = new QLabel(tr("No frames"));
        layout->addWidget(noFramesLabel);
    }

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
}

FrameListSection::~FrameListSection()
{
    delete ui;
}

void FrameListSection::addFrame() {

    Model::instance->addFrame();

    if (frames.size() == 0) {
        layout->removeWidget(noFramesLabel);
        delete noFramesLabel;

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

    ui->removeFrameButton->setEnabled(true);
    ui->spriteSizeComboBox->setDisabled(true);
}

void FrameListSection::removeFrame() {
    bool removed = Model::instance->removeFrame();

    if (!removed)
        return;

    ClickableLabel* frame = frames.at(frames.size() - 1);
    layout->removeWidget(frame);
    frames.pop_back();
    delete frame;

    if (frames.size() == 1) {
//        noFramesLabel = new QLabel(tr("No frames"));
//        layout->addWidget(noFramesLabel);
        ui->removeFrameButton->setDisabled(true);
        ui->spriteSizeComboBox->setEnabled(true);
    }
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
}

