#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
  auto layout = new QVBoxLayout{this};
  resultBar = new ResultBar{this};
  layout->addWidget(resultBar);
  InitSwitcher(layout);

  auto panel = new QWidget{this};
  auto panelLayout = new QHBoxLayout{panel};

  additionalPanel = new AdditionalCalculatorPanel{this};
  panelLayout->addWidget(additionalPanel);
  additionalPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  additionalPanel->ConnectButtons(resultBar);
  additionalPanel->hide();

  mainPanel = new MainCalculatorPanel{this};
  panelLayout->addWidget(mainPanel);
  mainPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mainPanel->ConnectButtons(resultBar);

  QObject::connect(mainPanel, &MainCalculatorPanel::PrintLabel, resultBar, &ResultBar::Append);

  layout->addWidget(panel);
  layout->setAlignment(Qt::AlignTop);
  setWindowTitle(tr("Калькулятор (обычный)"));

}

void MainWindow::InitSwitcher(QVBoxLayout *layout) {
  auto subBar = new QWidget{this};
  auto switcherLayout = new QHBoxLayout(subBar);
  auto switcher = new Switcher{subBar};
  QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spLeft.setHorizontalStretch(3);
  switcher->setSizePolicy(spLeft);
  switcherLayout->addWidget(switcher);
  auto clearButton = new QPushButton{subBar};
  QObject::connect(clearButton, &QPushButton::clicked, resultBar, &ResultBar::Clear);
  QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spRight.setHorizontalStretch(1);
  clearButton->setSizePolicy(spRight);
  clearButton->setText(tr("C"));
  switcherLayout->addWidget(clearButton);
  layout->addWidget(subBar);
  switcher->LinkWithWindow(this);
}

MainWindow::~MainWindow() {
}

void MainWindow::setCasualMode() {
  setWindowTitle(tr("Калькулятор (обычный)"));
  additionalPanel->hide();
}

void MainWindow::setProfessionalMode() {
  setWindowTitle(tr("Калькулятор (инженерный)"));
  additionalPanel->show();
}
