#include "maincalculatorpanel.h"

MainCalculatorPanel::MainCalculatorPanel(QWidget *parent) : QWidget(parent), buttons(new UnaryOperationButton* [2]) {
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
    auto equalButton = new EqualButton{};
    layout->addWidget(equalButton, 2, 4, 2, 1);


    buttons[0] = new UnaryOperationButton{[](double x) {return sqrt(x);}};
    buttons[1] = new UnaryOperationButton{[](double x) {return 1/x;}};

    buttons[0]->setText("\u221Ax");
    buttons[1]->setText("1/x");

    layout->addWidget(buttons[0], 0, 4);
    layout->addWidget(buttons[1], 1, 4);



}

void MainCalculatorPanel::Append(int number) {
    emit PrintLabel(number);
}

void MainCalculatorPanel::ConnectButtons(ResultBar *bar) {
    for (int i = 0; i < 2; ++i) {
        QObject::connect(buttons[i], &UnaryOperationButton::PressButtonSome, bar, &ResultBar::UnaryOperation);
    }
}
