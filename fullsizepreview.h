#ifndef FULLSIZEPREVIEW_H
#define FULLSIZEPREVIEW_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class FullSizePreview;
}

class FullSizePreview : public QDialog
{
    Q_OBJECT

public:
    explicit FullSizePreview(QWidget *parent = nullptr);
    ~FullSizePreview();

private:
    Ui::FullSizePreview *ui;
    int frameIndex;
    QTimer timer;

    void showImage();
};

#endif // FULLSIZEPREVIEW_H
