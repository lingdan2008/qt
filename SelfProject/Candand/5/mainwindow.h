#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

 private slots:
  void on_actionNew_Window_triggered();

 private:
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
