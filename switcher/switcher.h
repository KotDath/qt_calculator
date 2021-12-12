#ifndef SWITCHER_H
#define SWITCHER_H

#include <QRadioButton>
#include <QVBoxLayout>
#include <QDebug>

class MainWindow;

class Switcher : public QWidget
{
    Q_OBJECT
public:
    explicit Switcher(QWidget *parent = nullptr);

    void LinkWithWindow(MainWindow* window);
private:
    QRadioButton* casualMode;
    QRadioButton* professionalMode;
};

#endif // SWITCHER_H
