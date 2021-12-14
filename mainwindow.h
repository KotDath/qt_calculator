#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <result_bar/resultbar.h>
#include <switcher/switcher.h>
#include "submenu/maincalculatorpanel.h"
#include "submenu/additionalcalculatorpanel.h"
#include "buttons/clearbutton.h"

//!!! В этой ЛР не нужно использовать QMainWindow. Калькулятор должен быть на основе QWidget

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  void InitOutputLabel(QVBoxLayout *layout);
  void InitSwitcher(QVBoxLayout *layout);
  ~MainWindow();

 public
  slots:
      void setCasualMode();
  void setProfessionalMode();
 private:
  MainCalculatorPanel *mainPanel;
  AdditionalCalculatorPanel *additionalPanel;
  ResultBar *resultBar;
};
#endif // MAINWINDOW_H
