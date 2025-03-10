#ifndef FINDFILEDIALOG_H
#define FINDFILEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableWidget;
class QResizeEvent;
QT_END_NAMESPACE

class FindFileDialog : public QDialog {
  Q_OBJECT

 public:
  FindFileDialog(QWidget *parent = 0);
  ~FindFileDialog();

 protected:
  void resizeEvent(QResizeEvent *event);

 private:
  QLabel *namedLabel;
  QLineEdit *lookInLineEdit;
  QLabel *lookInLabel;
  QLineEdit *namedLineEdit;

  QCheckBox *subfoldersCheckBox;
  QTableWidget *tableWidget;
  QLabel *messageLabel;

  QPushButton *findButton;
  QPushButton *stopButton;
  QPushButton *closeButton;
  QPushButton *helpButton;
};

#endif  // FINDFILEDIALOG_H
