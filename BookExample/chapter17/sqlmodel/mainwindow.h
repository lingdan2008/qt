﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if QT_VERSION >= 0x050000
#include <QMainWindow>
#else
#include <QMainWindow>
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

 protected:
  void changeEvent(QEvent *e);

 private:
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
