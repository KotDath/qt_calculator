#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
  QWidget *window = new QWidget{};
  
  //!!! Код не должен быть шире 100 символов.
  window->setStyleSheet(
      "background-color: rgba(255, 255, 255, 160) QPushButton#pushButton:hover { background-color: rgb(224, 255, 0); } QPushButton#pushButton:pressed { background-color: rgb(224, 0, 0);}");
  
  
  auto layout = new QVBoxLayout{window};
  resultBar = new ResultBar{};
  layout->addWidget(resultBar);
  InitSwitcher(layout);

  //!!! Для всех объектов желательно сразу задавать объект-родитель при создании. 
  auto panel = new QWidget{};
  auto panelLayout = new QHBoxLayout{panel};

  additionalPanel = new AdditionalCalculatorPanel{};
  panelLayout->addWidget(additionalPanel);
  additionalPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  additionalPanel->ConnectButtons(resultBar);
  additionalPanel->hide();

  mainPanel = new MainCalculatorPanel{};
  panelLayout->addWidget(mainPanel);
  mainPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  mainPanel->ConnectButtons(resultBar);

  QObject::connect(mainPanel, &MainCalculatorPanel::PrintLabel, resultBar, &ResultBar::Append);

  layout->addWidget(panel);
  layout->setAlignment(Qt::AlignTop);
  setCentralWidget(window);
  setWindowTitle("Калькулятор (обычный)"); //!!! Строки, которые отображаются в интерфейсе, лучше помещать в tr("...")

}

void MainWindow::InitOutputLabel(QVBoxLayout *layout) {

}

void MainWindow::InitSwitcher(QVBoxLayout *layout) {
  auto subBar = new QWidget{};
  auto switcherLayout = new QHBoxLayout(subBar);
  auto switcher = new Switcher{};
  QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spLeft.setHorizontalStretch(3);
  switcher->setSizePolicy(spLeft);
  switcherLayout->addWidget(switcher);
  auto clearButton = new ClearButton{};
  QObject::connect(clearButton, &ClearButton::clicked, resultBar, &ResultBar::Clear);
  QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
  spRight.setHorizontalStretch(1);
  clearButton->setSizePolicy(spRight);
  clearButton->setText("C");
  switcherLayout->addWidget(clearButton);
  layout->addWidget(subBar);
  switcher->LinkWithWindow(this);
}

MainWindow::~MainWindow() {
}

void MainWindow::setCasualMode() {
  setWindowTitle("Калькулятор (обычный)");//!!! Строки, которые отображаются в интерфейсе, лучше помещать в tr("...")
  additionalPanel->hide();
}

void MainWindow::setProfessionalMode() {
  setWindowTitle("Калькулятор (инженерный)");//!!! Строки, которые отображаются в интерфейсе, лучше помещать в tr("...")
  additionalPanel->show();
}
