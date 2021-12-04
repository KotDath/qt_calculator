#include "switcher.h"

Switcher::Switcher(QWidget *parent) : QWidget(parent)
{
    auto topLayout = new QVBoxLayout{this};
    auto button1 = new QRadioButton("Обычный");
    auto button2 = new QRadioButton("Инженерный");
    topLayout->addWidget(button1);
    topLayout->addWidget(button2);
    setStyleSheet("background-color: brown");
}

