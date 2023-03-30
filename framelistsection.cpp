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
    sectionSize.setHeight(sectionSize.height() - 60);
    scrollArea->setFixedSize(sectionSize);

    widget = new QWidget;
    scrollArea->setWidget(widget);

    // set up layout
    layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop);

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
}

void FrameListSection::removeFrame() {
    bool removed = Model::instance->removeFrame();

    if (!removed)
        return;

    ClickableLabel* frame = frames.at(frames.size() - 1);
    layout->removeWidget(frame);
    frames.pop_back();
    delete frame;

    if (frames.empty()) {
        noFramesLabel = new QLabel(tr("No frames"));
        layout->addWidget(noFramesLabel);
    }
}

