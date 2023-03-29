#include "framelistsection.h"
#include "ui_framelistsection.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "QScrollArea"
#include "QLabel"
#include "QSize"
#include <vector>

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

    vector<QPushButton*> frames;

    for (int i = 0; i < 420; i++) {
        QPushButton* button = new QPushButton(tr("frame%1").arg(i));
        button->setMinimumSize(100, 100);
        button->setFixedSize(120, 120);

        frames.push_back(button);
    }



    for (auto& e : frames) {
        layout->addWidget(e);
    }

    frames[2]->hide();

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
