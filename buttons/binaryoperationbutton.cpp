#include "binaryoperationbutton.h"

BinaryOperationButton::BinaryOperationButton(std::function<double(double, double)> op, char name, QWidget *parent)
    : QPushButton(parent), unaryOperation(op), opName(name) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  QFont font = this->font();
  font.setPointSize(16);
  setFont(font);
}

void BinaryOperationButton::mousePressEvent(QMouseEvent *e) {
  QPushButton::mousePressEvent(e);
  emit PressButtonSome(unaryOperation, opName);
}

void BinaryOperationButton::mouseReleaseEvent(QMouseEvent *e) {
  QPushButton::mouseReleaseEvent(e);
}
