#ifndef EDITINGSECTION_H
#define EDITINGSECTION_H

#include <QWidget>

namespace Ui {
class EditingSection;
}

class EditingSection : public QWidget
{
    Q_OBJECT

public:
    explicit EditingSection(QWidget *parent = nullptr);
    ~EditingSection();

private:
    Ui::EditingSection *ui;
};

#endif // EDITINGSECTION_H
