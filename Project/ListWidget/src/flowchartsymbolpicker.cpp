#include <QDialogButtonBox>
#include <QListWidget>
#include <QMap>
#include <QMapIterator>
#include <QVBoxLayout>

#include "flowchartsymbolpicker.h"

FlowChartSymbolPicker::FlowChartSymbolPicker(
    const QMap<int, QString>& symbolMap, QWidget* parent)
    : QDialog(parent) {
  id = -1;

  listWidget = new QListWidget;
  listWidget->setIconSize(QSize(60, 60));

  QMapIterator<int, QString> i(symbolMap);
  while (i.hasNext()) {
    i.next();
    QListWidgetItem* item = new QListWidgetItem(i.value(), listWidget);
    item->setIcon(iconForSymbol(i.value()));
    item->setData(Qt::UserRole, i.key());
  }

  buttonBox =
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(reject()));

  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainLayout->addWidget(listWidget);
  mainLayout->addWidget(buttonBox);
  this->setLayout(mainLayout);

  this->setWindowTitle(tr("Flow Chart Symbol Picker"));
}

int FlowChartSymbolPicker::selectedId() const { return this->id; }

void FlowChartSymbolPicker::done(int result) {
  id = -1;
  if (result == QDialog::Accepted) {
    QListWidgetItem* item = listWidget->currentItem();
    if (item) {
      id = item->data(Qt::UserRole).toInt();
    }
  }
  QDialog::done(result);
}

FlowChartSymbolPicker::~FlowChartSymbolPicker() {}

QIcon FlowChartSymbolPicker::iconForSymbol(const QString& symbolName) {
  QString fileName = ":/images/" + symbolName.toLower();
  fileName.replace(' ', '-');
  return QIcon(fileName);
}
