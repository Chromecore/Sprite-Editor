#ifndef FRAMELISTSECTION_H
#define FRAMELISTSECTION_H

#include <QWidget>

namespace Ui {
class FrameListSection;
}

class FrameListSection : public QWidget
{
    Q_OBJECT

public:
    explicit FrameListSection(QWidget *parent = nullptr);
    ~FrameListSection();

private:
    Ui::FrameListSection *ui;

protected:

};

#endif // FRAMELISTSECTION_H
