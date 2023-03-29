#include "framelistsection.h"
#include "ui_framelistsection.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "QScrollArea"
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

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QSize sectionSize(this->size());
    sectionSize.setHeight(sectionSize.height() - 60);
    scrollArea->setFixedSize(sectionSize);

    QWidget* w = new QWidget;
    scrollArea->setWidget(w);
    QVBoxLayout* layout = new QVBoxLayout(w);
    layout->setAlignment(Qt::AlignTop);

    // get frames list from model
    // showFrames();

//    vector<ClickableLabel*> frames1;

    vector<QPixmap*>& frames = Model::instance->getPixmaps();

    for (QPixmap* frame : frames) {
        ClickableLabel* clickLabel = new ClickableLabel;
        clickLabel->setMinimumSize(100, 100);
        clickLabel->setFixedSize(120, 120);
        clickLabel->setPixmap(frame->scaled(120, 120));

        layout->addWidget(clickLabel);
    }

//    QPixmap* cur = Model::instance->getPixmap();

//    for (int i = 0; i < 420; i++) {
//        ClickableLabel* clickLabel = new ClickableLabel;
//        clickLabel->setMinimumSize(100, 100);
//        clickLabel->setFixedSize(120, 120);
//        clickLabel->setPixmap(cur->scaled(120, 120));

////        QIcon icon(*cur);
////        button->setIcon(icon);
////        button->setIconSize(button->size());

//        frames1.push_back(clickLabel);
//    }



//    for (auto& e : frames1) {
//        layout->addWidget(e);
//    }

    if (frames.empty()) {
        QLabel* label = new QLabel(tr("No frames"));
        layout->addWidget(label);
    }

//    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);
//    layout->setSpacing(10);
//    ui->scrollArea->setWidget(layout);
}

FrameListSection::~FrameListSection()
{
    delete ui;
}
