#include "resultbar.h"
ResultBar::ResultBar(QWidget *parent) : QWidget(parent), currentBinaryOperation(nullptr) {
  auto topLayout = new QHBoxLayout{this};
  resultText = new QLineEdit{};
  resultText->setText("0");
  resultText->setAlignment(Qt::AlignRight);
  topLayout->addWidget(resultText);
  resultText->setFixedHeight(100);
  auto font = resultText->font();
  font.setFamily("monospace [Consolas]");
  font.setPointSize(40);
  resultText->setFont(font);
  resultText->setReadOnly(true);
}

void ResultBar::Append(int number) {
  double bufferNumber = firstNumber;
  if (currentBinaryOperation != nullptr) {
    secondArgumentBegin = true;
    bufferNumber = secondNumber;
  }

  if (realPart == 0) {
    bufferNumber *= 10;
    bufferNumber += number;
  } else {
    bufferNumber += static_cast<double>(number) * pow(10, -realPart);
    ++realPart;
    if (bufferNumber == 0) {
      resultText->insert("0");
      return;
    }
  }
  if (secondArgumentBegin) {
    secondNumber = bufferNumber;
    QString result = resultText->text();
    result = resultText->text().mid(0, result.indexOf(currentOperationChar) + 1) + QString::number(secondNumber);
    resultText->setText(result);
  } else {
    firstNumber = bufferNumber;
    resultText->setText(QString::number(firstNumber));
  }
}

void ResultBar::UnaryOperation(std::function<double(double)> op) {
  if (secondArgumentBegin) {
    Calculate();
  }

  firstNumber = op(firstNumber);
  resultText->setText(QString::number(firstNumber));
  unaryOperationPass = true;
  realPart = 0;
}

void ResultBar::BinaryOperation(std::function<double(double, double)> op, char name) {

  if (currentBinaryOperation == nullptr) {
    QString buffer = resultText->text();
    buffer += name;
    resultText->setText(buffer);
    resultText->setText(buffer);
    realPart = 0;
  } else {
    if (secondArgumentBegin) {
      Calculate();
      QString buffer = resultText->text();
      buffer += name;
      resultText->setText(buffer);
      resultText->setText(buffer);
    } else {
      QString buffer = resultText->text();
      buffer.chop(1);
      buffer += name;
      resultText->setText(buffer);
    }
  }

  currentBinaryOperation = op;
  currentOperationChar = name;
}

void ResultBar::Clear() {
  firstNumber = 0;
  secondNumber = 0;
  realPart = 0;
  unaryOperationPass = false;
  currentBinaryOperation = nullptr;
  secondArgumentBegin = false;
  currentOperationChar = ' ';
  resultText->setText(QString::number(firstNumber));
}

void ResultBar::DotPrint() {
  ++realPart;
  resultText->insert(".");
}

void ResultBar::Calculate() {
  if (currentBinaryOperation == nullptr) {
    return;
  }

  if (!secondArgumentBegin) {
    firstNumber = currentBinaryOperation(firstNumber, firstNumber);
  } else {
    firstNumber = currentBinaryOperation(firstNumber, secondNumber);
  }

  secondNumber = 0;
  resultText->setText(QString::number(firstNumber));
  currentBinaryOperation = nullptr;
  unaryOperationPass = false;
  realPart = 0;
  secondArgumentBegin = false;
}
