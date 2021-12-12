#include "additionalcalculatorpanel.h"

AdditionalCalculatorPanel::AdditionalCalculatorPanel(QWidget *parent) : QWidget(parent), buttons(new UnaryOperationButton* [16])
{
    auto layout = new QGridLayout{this};
    InitActions();
    InitNames();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            layout->addWidget(buttons[i * 4 + j], i, j);
        }
    }
}


void AdditionalCalculatorPanel::InitNames() {
    buttons[0]->setText("sinh");
    buttons[1]->setText("sin");
    buttons[2]->setText("exp");
    buttons[3]->setText("x\u00B2");
    buttons[4]->setText("cosh");
    buttons[5]->setText("cos");
    buttons[6]->setText("ln");
    buttons[7]->setText("x\u00B3");
    buttons[8]->setText("tanh");
    buttons[9]->setText("tan");
    buttons[10]->setText("log");
    buttons[11]->setText("x\u207F");
    buttons[12]->setText("n!");
    buttons[13]->setText("\u03C0");
    buttons[14]->setText("3\u221Ax");
    buttons[15]->setText("y\u221Ax");
}

void AdditionalCalculatorPanel::InitActions() {
    buttons[0] = new UnaryOperationButton([](double x) {return sinh(x);});
    buttons[1] = new UnaryOperationButton([](double x) {return sin(x);});
    buttons[2] = new UnaryOperationButton([](double x) {return exp(x);});
    buttons[3] = new UnaryOperationButton([](double x) {return x * x;});
    buttons[4] = new UnaryOperationButton([](double x) {return cosh(x);});
    buttons[5] = new UnaryOperationButton([](double x) {return cos(x);});
    buttons[6] = new UnaryOperationButton([](double x) {return log(x);});
    buttons[7] = new UnaryOperationButton([](double x) {return x * x * x;});
    buttons[8] = new UnaryOperationButton([](double x) {return tanh(x);});
    buttons[9] = new UnaryOperationButton([](double x) {return tan(x);});
    buttons[10] = new UnaryOperationButton([](double x) {return log10(x);});
    buttons[11] = new UnaryOperationButton([](double x) {return 0;});
    buttons[12] = new UnaryOperationButton([](double x) {return tgamma(x + 1);});
    buttons[13] = new UnaryOperationButton([](double x) {return M_PI;});
    buttons[14] = new UnaryOperationButton([](double x) {return cbrt(x);});
    buttons[15] = new UnaryOperationButton([](double x) {return 0;});
}

void AdditionalCalculatorPanel::ConnectButtons(ResultBar* bar) {
    for (int i = 0; i < 16; ++i) {
        QObject::connect(buttons[i], &UnaryOperationButton::PressButtonSome, bar, &ResultBar::UnaryOperation);
    }
}
