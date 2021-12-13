#ifndef RESULTBAR_H
#define RESULTBAR_H

#include <QHBoxLayout>
#include <QLineEdit>

class ResultBar : public QWidget {
  Q_OBJECT
 public:
  explicit ResultBar(QWidget *parent = nullptr);
 public
  slots:
      void Append(int
  number);
  void UnaryOperation(std::function<double(double)> op);
  void BinaryOperation(std::function<double(double, double)> op, char name);
  void DotPrint();
  void Clear();
  void Calculate();
 private:
  QLineEdit *resultText;
  double firstNumber = 0;
  double secondNumber = 0;
  bool unaryOperationPass = false;
  int realPart = 0;
  bool secondArgumentBegin = false;
  char currentOperationChar = ' ';
  std::function<double(double, double)> currentBinaryOperation;

};

#endif // RESULTBAR_H
