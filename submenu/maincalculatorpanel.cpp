#include "maincalculatorpanel.h"

MainCalculatorPanel::MainCalculatorPanel(QWidget *parent)
    : QWidget(parent), unaryButtons(new UnaryOperationButton *[2]), binaryButtons(new BinaryOperationButton *[4]) {
  auto layout = new QGridLayout{this};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      auto numButton = new NumberButton(i * 3 + j + 1);
      QObject::connect(numButton, &NumberButton::PressButtonSome, this, &MainCalculatorPanel::Append);
      layout->addWidget(numButton, 3 - i - 1, j);
    }
  }

  auto zeroButton = new NumberButton(0);
  QObject::connect(zeroButton, &NumberButton::PressButtonSome, this, &MainCalculatorPanel::Append);
  layout->addWidget(zeroButton, 3, 0, 1, 2);
  equalButton = new EqualButton{};
  layout->addWidget(equalButton, 2, 4, 2, 1);

  unaryButtons[0] = new UnaryOperationButton{[](double x) { return sqrt(x); }};
  unaryButtons[1] = new UnaryOperationButton{[](double x) { return 1 / x; }};

  unaryButtons[0]->setText("\u221Ax");
  unaryButtons[1]->setText("1/x");

  layout->addWidget(unaryButtons[0], 0, 4);
  layout->addWidget(unaryButtons[1], 1, 4);

  dotButton = new DotButton{};
  layout->addWidget(dotButton, 3, 2);

  binaryButtons[0] = new BinaryOperationButton{[](double x, double y) { return x / y; }, '/'};
  binaryButtons[1] = new BinaryOperationButton{[](double x, double y) { return x * y; }, '*'};
  binaryButtons[2] = new BinaryOperationButton{[](double x, double y) { return x - y; }, '-'};
  binaryButtons[3] = new BinaryOperationButton{[](double x, double y) { return x + y; }, '+'};

  binaryButtons[0]->setText("/");
  binaryButtons[1]->setText("*");
  binaryButtons[2]->setText("-");
  binaryButtons[3]->setText("+");

  for (int i = 0; i < 4; ++i) {
    layout->addWidget(binaryButtons[i], i, 3);
  }

}

void MainCalculatorPanel::Append(int number) {
  emit PrintLabel(number);
}

void MainCalculatorPanel::ConnectButtons(ResultBar *bar) {
  for (int i = 0; i < 2; ++i) {
    QObject::connect(unaryButtons[i], &UnaryOperationButton::PressButtonSome, bar, &ResultBar::UnaryOperation);
  }

  QObject::connect(dotButton, &DotButton::pressed, bar, &ResultBar::DotPrint);
  QObject::connect(equalButton, &EqualButton::clicked, bar, &ResultBar::Calculate);

  for (int i = 0; i < 4; ++i) {
    QObject::connect(binaryButtons[i], &BinaryOperationButton::PressButtonSome, bar, &ResultBar::BinaryOperation);
  }
}
