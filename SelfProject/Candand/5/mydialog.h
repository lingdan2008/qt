#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog {
  Q_OBJECT

 public:
  explicit MyDialog(QWidget *parent = 0);
  ~MyDialog();

 protected:
  void changeEvent(QEvent *e);

 private:
  Ui::MyDialog *ui;
};

#endif  // MYDIALOG_H
