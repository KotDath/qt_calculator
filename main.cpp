#include "mainwindow.h"

#include <QApplication>
#include <result_bar/resultbar.h>
#include <QFile>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QFile styleFile(":/main.qss");
  styleFile.open(QFile::ReadOnly);
  QString style(styleFile.readAll());
  app.setStyleSheet(style);

  MainWindow window;
  window.resize(800, 600);
  window.show();
  return app.exec();
}
