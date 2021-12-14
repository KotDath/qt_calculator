#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <result_bar/resultbar.h>
#include <switcher/switcher.h>
#include "submenu/maincalculatorpanel.h"
#include "submenu/additionalcalculatorpanel.h"

class MainWindow : public QWidget {
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
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
