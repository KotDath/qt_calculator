#include "unaryoperationbutton.h"

UnaryOperationButton::UnaryOperationButton( std::function<double(double)> op, QWidget *parent): QPushButton(parent), unaryOperation(op) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont font = this->font();
    font.setPointSize(16);
    setFont(font);
}


void UnaryOperationButton::mousePressEvent(QMouseEvent *e) {
    QPushButton::mousePressEvent(e);
    emit PressButtonSome(unaryOperation);
}

void UnaryOperationButton::mouseReleaseEvent(QMouseEvent *e) {
    QPushButton::mouseReleaseEvent(e);
}

void UnaryOperationButton::setAction(std::function<double (double)> newOp) {
    unaryOperation = newOp;
}
