#ifndef MAINCALCULATORPANEL_H
#define MAINCALCULATORPANEL_H

#include <QGridLayout>
#include <QWidget>
#include "buttons/numberbutton.h"
#include "buttons/equalbutton.h"
#include "buttons/unaryoperationbutton.h"
#include "result_bar/resultbar.h"

class MainCalculatorPanel : public QWidget {
    Q_OBJECT
public:
    explicit MainCalculatorPanel(QWidget *parent = nullptr);
    void ConnectButtons(ResultBar* bar);
public slots:
    void Append(int number);
signals:
    void PrintLabel(int number);
private:
    UnaryOperationButton** buttons;
};

#endif // MAINCALCULATORPANEL_H
