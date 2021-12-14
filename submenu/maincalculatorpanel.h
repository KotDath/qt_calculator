#ifndef MAINCALCULATORPANEL_H
#define MAINCALCULATORPANEL_H

#include <QGridLayout>
#include <QWidget>
#include "buttons/numberbutton.h"
#include "buttons/unaryoperationbutton.h"
#include "result_bar/resultbar.h"
#include "buttons/binaryoperationbutton.h"

class MainCalculatorPanel : public QWidget {
  Q_OBJECT
 public:
  explicit MainCalculatorPanel(QWidget *parent = nullptr);
  void ConnectButtons(ResultBar *bar);
 public
  slots:
      void Append(int
  number);
  signals:
      void PrintLabel(int
  number);
 private:
  UnaryOperationButton **unaryButtons;
  BinaryOperationButton **binaryButtons;
  QPushButton *dotButton;
  QPushButton *equalButton;
};

#endif // MAINCALCULATORPANEL_H
