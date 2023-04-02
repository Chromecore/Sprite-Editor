#include "clickablelabel.h"
#include "model.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags)
    : QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent*) {
    Model::instance->setCurrentIndex(index);
}
