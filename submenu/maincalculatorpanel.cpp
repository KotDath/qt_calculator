#include "maincalculatorpanel.h"

MainCalculatorPanel::MainCalculatorPanel(QWidget *parent) : QWidget(parent) {
    auto layout = new QGridLayout{this};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto numButton = new NumberButton(i * 3 + j + 1);
            QObject::connect(numButton, &NumberButton::PressButtonSome, this, &MainCalculatorPanel::Append);
            layout->addWidget(numButton, 3 - i - 1, j);
        }
    }

    auto zeroButton = new NumberButton(0);
    layout->addWidget(zeroButton, 4, 0, 1, 2);
}

void MainCalculatorPanel::Append(QString str) {
    emit PrintLabel(str);
}
