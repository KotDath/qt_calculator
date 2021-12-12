#ifndef ADDITIONALCALCULATORPANEL_H
#define ADDITIONALCALCULATORPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "buttons/unaryoperationbutton.h"
#include "result_bar/resultbar.h"

class AdditionalCalculatorPanel : public QWidget
{
    Q_OBJECT
public:
    explicit AdditionalCalculatorPanel(QWidget *parent = nullptr);
    void InitNames();
    void InitActions();
    void ConnectButtons(ResultBar* bar);
private:
    UnaryOperationButton** buttons;

};

#endif // ADDITIONALCALCULATORPANEL_H
