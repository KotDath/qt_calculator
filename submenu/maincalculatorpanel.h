#ifndef MAINCALCULATORPANEL_H
#define MAINCALCULATORPANEL_H

#include <QGridLayout>
#include <QWidget>
#include "buttons/numberbutton.h"

class MainCalculatorPanel : public QWidget {
    Q_OBJECT
public:
    explicit MainCalculatorPanel(QWidget *parent = nullptr);
public slots:
    void Append(QString str);
signals:
    void PrintLabel(QString str);
};

#endif // MAINCALCULATORPANEL_H
