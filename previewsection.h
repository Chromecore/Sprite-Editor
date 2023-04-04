#ifndef PREVIEWSECTION_H
#define PREVIEWSECTION_H

#include <QWidget>
#include <QTime>
#include <QPixmap>
#include <QTimer>
#include "clickablelabel.h"

namespace Ui {
class PreviewSection;
}

class PreviewSection : public QWidget
{
    Q_OBJECT

public:
    explicit PreviewSection(QWidget *parent = nullptr);
    ~PreviewSection();
    void showImage();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::PreviewSection *ui;
    QTimer timer;
    ClickableLabel clickLabel;
};

#endif // PREVIEWSECTION_H
