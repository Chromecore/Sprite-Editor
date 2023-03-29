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

    QWidget* widget = new QWidget;
    scrollArea->setWidget(widget);

    layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignTop);

    vector<QPixmap*>& frames = Model::instance->getPixmaps();

    for (QPixmap* frame : frames) {
        ClickableLabel* clickLabel = new ClickableLabel;
        clickLabel->setMinimumSize(100, 100);
        clickLabel->setFixedSize(120, 120);
        clickLabel->setPixmap(frame->scaled(118, 118));
        clickLabel->setLineWidth(2);
        clickLabel->setFrameStyle(1);

        layout->addWidget(clickLabel);
    }

    if (frames.empty()) {
        QLabel* label = new QLabel(tr("No frames"));
        layout->addWidget(label);
    }

    connect(ui->addFrameButton,
            &QPushButton::clicked,
            this,
            &FrameListSection::addFrame);
}

FrameListSection::~FrameListSection()
{
    delete ui;
}

void FrameListSection::addFrame() {

    Model::instance->addFrame();

    vector<QPixmap*> frames = Model::instance->getPixmaps();
    ClickableLabel* clickLabel = new ClickableLabel;
    clickLabel->setMinimumSize(100, 100);
    clickLabel->setFixedSize(120, 120);
    clickLabel->setPixmap(frames.at(frames.size() - 1)->scaled(118, 118));
    clickLabel->setLineWidth(2);
    clickLabel->setFrameStyle(1);
    layout->addWidget(clickLabel);
}
