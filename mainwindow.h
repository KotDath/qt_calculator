#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <result_bar/resultbar.h>
#include <switcher/switcher.h>
#include <submenu/maincalculatorpanel.h>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    void InitOutputLabel(QVBoxLayout* layout);
    void InitSwitcher(QVBoxLayout* layout);
    ~MainWindow();

};
#endif // MAINWINDOW_H
