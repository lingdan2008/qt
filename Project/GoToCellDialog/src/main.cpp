#include <QApplication>

#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  GoToCellDialog *dialog = new GoToCellDialog;
  dialog->show();

  return app.exec();
}
