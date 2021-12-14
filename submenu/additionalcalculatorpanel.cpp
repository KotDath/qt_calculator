#include "additionalcalculatorpanel.h"

AdditionalCalculatorPanel::AdditionalCalculatorPanel(QWidget *parent)
    : QWidget(parent), unaryButtons(new UnaryOperationButton *[14]), binaryButtons(new BinaryOperationButton *[2]) {
  auto layout = new QGridLayout{this};
  InitActions();
  InitNames();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      layout->addWidget(unaryButtons[i * 4 + j], i, j);
    }
  }

  for (int i = 0; i < 3; ++i) {
    layout->addWidget(unaryButtons[8 + i], 2, i);
  }

  for (int i = 0; i < 3; ++i) {
    layout->addWidget(unaryButtons[11 + i], 3, i);
  }

  layout->addWidget(binaryButtons[0], 2, 3);
  layout->addWidget(binaryButtons[1], 3, 3);
}

void AdditionalCalculatorPanel::InitNames() {
  unaryButtons[0]->setText(tr("sinh"));
  unaryButtons[1]->setText(tr("sin"));
  unaryButtons[2]->setText(tr("exp"));
  unaryButtons[3]->setText(tr("x\u00B2"));
  unaryButtons[4]->setText(tr("cosh"));
  unaryButtons[5]->setText(tr("cos"));
  unaryButtons[6]->setText(tr("ln"));
  unaryButtons[7]->setText(tr("x\u00B3"));
  unaryButtons[8]->setText(tr("tanh"));
  unaryButtons[9]->setText(tr("tan"));
  unaryButtons[10]->setText(tr("log"));
  unaryButtons[11]->setText(tr("n!"));
  unaryButtons[12]->setText(tr("\u03C0"));
  unaryButtons[13]->setText(tr("\u00B3\u221Ax"));

  binaryButtons[0]->setText(tr("x\u207F"));
  binaryButtons[1]->setText(tr("\u207F\u221Ax"));
}

void AdditionalCalculatorPanel::InitActions() {
  unaryButtons[0] = new UnaryOperationButton([](double x) { return sinh(x); }, this);
  unaryButtons[1] = new UnaryOperationButton([](double x) { return sin(x); }, this);
  unaryButtons[2] = new UnaryOperationButton([](double x) { return exp(x); }, this);
  unaryButtons[3] = new UnaryOperationButton([](double x) { return x * x; }, this);
  unaryButtons[4] = new UnaryOperationButton([](double x) { return cosh(x); }, this);
  unaryButtons[5] = new UnaryOperationButton([](double x) { return cos(x); }, this);
  unaryButtons[6] = new UnaryOperationButton([](double x) { return log(x); }, this);
  unaryButtons[7] = new UnaryOperationButton([](double x) { return x * x * x; }, this);
  unaryButtons[8] = new UnaryOperationButton([](double x) { return tanh(x); }, this);
  unaryButtons[9] = new UnaryOperationButton([](double x) { return tan(x); }, this);
  unaryButtons[10] = new UnaryOperationButton([](double x) { return log10(x); }, this);
  unaryButtons[11] = new UnaryOperationButton([](double x) { return tgamma(x + 1); }, this);
  unaryButtons[12] = new UnaryOperationButton([](double x) { return M_PI; }, this);
  unaryButtons[13] = new UnaryOperationButton([](double x) { return cbrt(x); }, this);

  binaryButtons[0] = new BinaryOperationButton([](double x, double y) { return pow(x, y); }, '^', this);
  binaryButtons[1] = new BinaryOperationButton([](double x, double y) { return pow(x, 1 / y); }, '"', this);
}

void AdditionalCalculatorPanel::ConnectButtons(ResultBar *bar) {
  for (int i = 0; i < 14; ++i) {
    QObject::connect(unaryButtons[i], &UnaryOperationButton::PressButtonSome, bar, &ResultBar::UnaryOperation);
  }

  for (int i = 0; i < 2; ++i) {
    QObject::connect(binaryButtons[i], &BinaryOperationButton::PressButtonSome, bar, &ResultBar::BinaryOperation);
  }
}
