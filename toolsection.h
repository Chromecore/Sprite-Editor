#ifndef TOOLSECTION_H
#define TOOLSECTION_H

#include <QWidget>

namespace Ui {
class ToolSection;
}

class ToolSection : public QWidget
{
    Q_OBJECT

public:
    explicit ToolSection(QWidget *parent = nullptr);
    ~ToolSection();

private:
    Ui::ToolSection *ui;
};

#endif // TOOLSECTION_H
