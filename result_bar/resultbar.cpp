#include "resultbar.h"
ResultBar::ResultBar(QWidget *parent) : QWidget(parent) {
    auto topLayout = new QHBoxLayout{this};
    resultText = new QLineEdit{};
    resultText->setText("0");
    resultText->setAlignment(Qt::AlignRight);
    topLayout->addWidget(resultText);
    resultText->setFixedHeight(100);
    auto font = resultText->font();
    font.setFamily("monospace [Consolas]");
    font.setPointSize(40);
    resultText->setFont(font);
    resultText->setReadOnly(true);
}

void ResultBar::Append(int number) {
    if (unaryOperationPass) {
         firstNumber = number;
         unaryOperationPass = false;
    } else {
        firstNumber *= 10;
        firstNumber += number;
    }
    resultText->setText(QString::number(firstNumber));
}

void ResultBar::UnaryOperation(std::function<double(double)> op) {
    firstNumber = op(firstNumber);
    resultText->setText(QString::number(firstNumber));
    unaryOperationPass = true;
}

void ResultBar::Clear() {
    firstNumber = 0;
    resultText->setText(QString::number(firstNumber));
}
