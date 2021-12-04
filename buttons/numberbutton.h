#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H

#include <QPushButton>

class NumberButton : public QPushButton {
    Q_OBJECT
public:
    NumberButton(int number = 0, QWidget *parent = nullptr);
private:
    int number;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void PressButtonSome(QString str);
};

#endif // NUMBERBUTTON_H
