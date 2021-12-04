#include "resultbar.h"
ResultBar::ResultBar(QWidget *parent) : QWidget(parent) {
    auto topLayout = new QHBoxLayout{this};
    resultText = new QLineEdit{};
    resultText->setAlignment(Qt::AlignRight);
    topLayout->addWidget(resultText);
    setStyleSheet("background-color: red");
    resultText->setFixedHeight(100);
    auto font = resultText->font();
    font.setFamily("monospace [Consolas]");
    font.setPointSize(40);
    resultText->setFont(font);
    resultText->setReadOnly(true);
}

void ResultBar::Append(QString str) {
    resultText->insert(str);
}
