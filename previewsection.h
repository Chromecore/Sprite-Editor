#ifndef PREVIEWSECTION_H
#define PREVIEWSECTION_H

#include <QWidget>
#include <QTime>
#include <QPixmap>
#include <QTimer>
#include <QLabel>

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
    void onFullSizeClicked();
    void onFPSSliderChanged(int value);

private:
    Ui::PreviewSection *ui;
    QTimer timer;
    QLabel label;
};

#endif // PREVIEWSECTION_H
