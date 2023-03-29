#ifndef FRAMELISTSECTION_H
#define FRAMELISTSECTION_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>

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

private:
    Ui::FrameListSection *ui;
    QScrollArea* scrollArea;
    QVBoxLayout* layout;

};

#endif // FRAMELISTSECTION_H
