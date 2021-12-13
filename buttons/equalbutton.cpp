#include "equalbutton.h"

EqualButton::EqualButton(QWidget *parent) : QPushButton(parent) {
  setText(QString("="));
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  QFont font = this->font();
  font.setPointSize(16);
  setFont(font);
}
