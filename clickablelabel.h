/*
Coleman Cook, Jack Koster, Jonathan Mercado, Tayin Wallace
CS 3505
A7: Sprite Editor Implementation
*/

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

// Class that inherets QLabel and can sense a mousePressEvent
class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    // Constructor for ClickableLabel object
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags = Qt::WindowFlags());

    // ClickableLabel destructor
    ~ClickableLabel();

    int index;

protected:
    // Sets the model's current index to the index of the frame clicked on
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
