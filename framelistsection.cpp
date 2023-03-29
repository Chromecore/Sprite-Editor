#include "framelistsection.h"
#include "ui_framelistsection.h"
#include "QVBoxLayout"
#include "QPushButton"
#include "QScrollArea"
#include "QLabel"
#include <vector>

using std::vector;

FrameListSection::FrameListSection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameListSection)
{
    ui->setupUi(this);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedSize(this->size());

    QWidget* w = new QWidget;
    scrollArea->setWidget(w);
    QVBoxLayout* layout = new QVBoxLayout(w);

    vector<QPushButton*> frames;

    for (int i = 0; i < 2; i++) {
        QPushButton* button = new QPushButton(tr("frame%1").arg(i));
        button->setMinimumSize(100, 100);

        frames.push_back(button);
    }



    for (auto& e : frames) {
        layout->addWidget(e);
    }

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
