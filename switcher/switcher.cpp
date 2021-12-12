#include "switcher.h"
#include "mainwindow.h"

Switcher::Switcher(QWidget *parent) : QWidget(parent)
{
    auto topLayout = new QVBoxLayout{this};
    casualMode = new QRadioButton("Обычный");
    casualMode->setChecked(true);
    professionalMode = new QRadioButton("Инженерный");
    topLayout->addWidget(casualMode);
    topLayout->addWidget(professionalMode);
}

void Switcher::LinkWithWindow(MainWindow* window) {
    QObject::connect(casualMode, &QRadioButton::clicked, window, &MainWindow::setCasualMode);
    QObject::connect(professionalMode, &QRadioButton::clicked, window, &MainWindow::setProfessionalMode);
}
