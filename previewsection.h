#ifndef PREVIEWSECTION_H
#define PREVIEWSECTION_H

#include <QWidget>
#include "Model.h"
#include <QTime>
#include <QPixmap>

namespace Ui {
class PreviewSection;
}

class PreviewSection : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewSection(QWidget *parent = nullptr);
    ~PreviewSection();
    bool delay(int sec);

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::PreviewSection *ui;
};

#endif // PREVIEWSECTION_H
