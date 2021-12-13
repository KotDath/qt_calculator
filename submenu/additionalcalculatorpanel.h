#ifndef ADDITIONALCALCULATORPANEL_H
#define ADDITIONALCALCULATORPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "buttons/unaryoperationbutton.h"
#include "result_bar/resultbar.h"
#include "buttons/binaryoperationbutton.h"

class AdditionalCalculatorPanel : public QWidget {
  Q_OBJECT
 public:
  explicit AdditionalCalculatorPanel(QWidget *parent = nullptr);
  void InitNames();
  void InitActions();
  void ConnectButtons(ResultBar *bar);
 private:
  UnaryOperationButton **unaryButtons;
  BinaryOperationButton **binaryButtons;
};

#endif // ADDITIONALCALCULATORPANEL_H
