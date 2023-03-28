#ifndef PREVIEWSECTION_H
#define PREVIEWSECTION_H

#include <QWidget>

namespace Ui {
class PreviewSection;
}

class PreviewSection : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewSection(QWidget *parent = nullptr);
    ~PreviewSection();

private:
    Ui::PreviewSection *ui;
};

#endif // PREVIEWSECTION_H
