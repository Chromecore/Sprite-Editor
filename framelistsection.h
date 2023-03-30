#ifndef FRAMELISTSECTION_H
#define FRAMELISTSECTION_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "clickablelabel.h"
#include <vector>

using std::vector;

namespace Ui {
class FrameListSection;
}

class FrameListSection : public QWidget
{
    Q_OBJECT

public:
    explicit FrameListSection(QWidget *parent = nullptr);
    ~FrameListSection();

public slots:
    void addFrame();
    void removeFrame();

private:
    Ui::FrameListSection *ui;
    QScrollArea* scrollArea;
    QVBoxLayout* layout;
    QWidget* widget;
    vector<ClickableLabel*> frames;

};

#endif // FRAMELISTSECTION_H
