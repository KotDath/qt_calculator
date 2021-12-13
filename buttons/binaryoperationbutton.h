#ifndef BINARYOPERATIONBUTTON_H
#define BINARYOPERATIONBUTTON_H

#include <QPushButton>

class BinaryOperationButton : public QPushButton
{
    Q_OBJECT
public:
    BinaryOperationButton(std::function<double(double, double)> op = nullptr, char name = ' ', QWidget *parent = nullptr);
private:
    std::function<double(double, double)> unaryOperation;
    char opName;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void PressButtonSome(std::function<double(double, double)> op, char name);
};

#endif // BINARYOPERATIONBUTTON_H
