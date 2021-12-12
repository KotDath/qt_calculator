#ifndef UNARYOPERATIONBUTTON_H
#define UNARYOPERATIONBUTTON_H

#include <QPushButton>

class UnaryOperationButton : public QPushButton
{
    Q_OBJECT
public:
    UnaryOperationButton(std::function<double (double)> op = nullptr, QWidget *parent = nullptr);
    void setAction(std::function<double (double)> newOp);
private:
    std::function<double(double)> unaryOperation;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
signals:
    void PressButtonSome(std::function<double(double)> op);
};

#endif // UNARYOPERATIONBUTTON_H
