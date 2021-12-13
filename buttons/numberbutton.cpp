#include "numberbutton.h"

NumberButton::NumberButton(int number, QWidget *parent) : QPushButton(parent), number(number) {
  setText(QString::number(number));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  QFont font = this->font();
  font.setPointSize(16);
  setFont(font);
}

void NumberButton::mousePressEvent(QMouseEvent *e) {
  QPushButton::mousePressEvent(e);
  emit PressButtonSome(number);
}

void NumberButton::mouseReleaseEvent(QMouseEvent *e) {
  QPushButton::mouseReleaseEvent(e);
}
