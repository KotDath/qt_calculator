#ifndef RESULTBAR_H
#define RESULTBAR_H

#include <QHBoxLayout>
#include <QLineEdit>

class ResultBar : public QWidget {
    Q_OBJECT
public:
    explicit ResultBar(QWidget *parent = nullptr);
public slots:
    void Append(int number);
    void UnaryOperation(std::function<double(double)> op);
    void Clear();
private:
    QLineEdit* resultText;
    double firstNumber = 0;
    double secondNumber = 0;
    bool unaryOperationPass = false;
    bool isWholePart = true;
    bool binaryOperationBegin = false;

};

#endif // RESULTBAR_H
