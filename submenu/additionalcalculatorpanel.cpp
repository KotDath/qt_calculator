#include "additionalcalculatorpanel.h"

AdditionalCalculatorPanel::AdditionalCalculatorPanel(QWidget *parent) : QWidget(parent), unaryButtons(new UnaryOperationButton* [14]), binaryButtons(new BinaryOperationButton* [2])
{
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
    unaryButtons[0]->setText("sinh");
    unaryButtons[1]->setText("sin");
    unaryButtons[2]->setText("exp");
    unaryButtons[3]->setText("x\u00B2");
    unaryButtons[4]->setText("cosh");
    unaryButtons[5]->setText("cos");
    unaryButtons[6]->setText("ln");
    unaryButtons[7]->setText("x\u00B3");
    unaryButtons[8]->setText("tanh");
    unaryButtons[9]->setText("tan");
    unaryButtons[10]->setText("log");
    unaryButtons[11]->setText("n!");
    unaryButtons[12]->setText("\u03C0");
    unaryButtons[13]->setText("\u00B3\u221Ax");

    binaryButtons[0]->setText("x\u207F");
    binaryButtons[1]->setText("\u207F\u221Ax");
}

void AdditionalCalculatorPanel::InitActions() {
    unaryButtons[0] = new UnaryOperationButton([](double x) {return sinh(x);});
    unaryButtons[1] = new UnaryOperationButton([](double x) {return sin(x);});
    unaryButtons[2] = new UnaryOperationButton([](double x) {return exp(x);});
    unaryButtons[3] = new UnaryOperationButton([](double x) {return x * x;});
    unaryButtons[4] = new UnaryOperationButton([](double x) {return cosh(x);});
    unaryButtons[5] = new UnaryOperationButton([](double x) {return cos(x);});
    unaryButtons[6] = new UnaryOperationButton([](double x) {return log(x);});
    unaryButtons[7] = new UnaryOperationButton([](double x) {return x * x * x;});
    unaryButtons[8] = new UnaryOperationButton([](double x) {return tanh(x);});
    unaryButtons[9] = new UnaryOperationButton([](double x) {return tan(x);});
    unaryButtons[10] = new UnaryOperationButton([](double x) {return log10(x);});
    unaryButtons[11] = new UnaryOperationButton([](double x) {return tgamma(x + 1);});
    unaryButtons[12] = new UnaryOperationButton([](double x) {return M_PI;});
    unaryButtons[13] = new UnaryOperationButton([](double x) {return cbrt(x);});

    binaryButtons[0] = new BinaryOperationButton([](double x, double y) {return pow(x, y);}, '^');
    binaryButtons[1] = new BinaryOperationButton([](double x, double y) {return pow(x, 1 / y);}, '"');
}

void AdditionalCalculatorPanel::ConnectButtons(ResultBar* bar) {
    for (int i = 0; i < 14; ++i) {
        QObject::connect(unaryButtons[i], &UnaryOperationButton::PressButtonSome, bar, &ResultBar::UnaryOperation);
    }

    for (int i = 0; i < 2; ++i) {
        QObject::connect(binaryButtons[i], &BinaryOperationButton::PressButtonSome, bar, &ResultBar::BinaryOperation);
    }
}
