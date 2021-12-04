#ifndef RESULTBAR_H
#define RESULTBAR_H

#include <QHBoxLayout>
#include <QLineEdit>

class ResultBar : public QWidget {
    Q_OBJECT
public:
    explicit ResultBar(QWidget *parent = nullptr);
public slots:
    void Append(QString str);
private:
    QLineEdit* resultText;
};

#endif // RESULTBAR_H
