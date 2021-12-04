#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    auto layout = new QVBoxLayout{};
    auto resultBar = new ResultBar{};
    layout->addWidget(resultBar);
    InitSwitcher(layout);
    auto mainCalculatorPanel = new MainCalculatorPanel{};
    layout->addWidget(mainCalculatorPanel);
    mainCalculatorPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QObject::connect(mainCalculatorPanel, &MainCalculatorPanel::PrintLabel, resultBar, &ResultBar::Append);
    QWidget *window = new QWidget{};
    window->setLayout(layout);
    layout->setAlignment(Qt::AlignTop);
    setCentralWidget(window);
    setWindowTitle("Калькулятор (обычный)");
    setStyleSheet("background-color: yellow");


}

void MainWindow::InitOutputLabel(QVBoxLayout* layout) {

}

void MainWindow::InitSwitcher(QVBoxLayout* layout) {
    auto switcher = new Switcher{};
    layout->addWidget(switcher);
}

MainWindow::~MainWindow() {
}

