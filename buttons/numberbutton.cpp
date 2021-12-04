#include "numberbutton.h"

NumberButton::NumberButton(int number, QWidget *parent) : QPushButton(parent), number(number) {
    setText(QString::number(number));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void NumberButton::mousePressEvent(QMouseEvent *e){
    QPushButton::mousePressEvent(e);
    emit PressButtonSome(QString::number(number));
}

void NumberButton::mouseReleaseEvent(QMouseEvent *e){
    QPushButton::mouseReleaseEvent(e);
}
