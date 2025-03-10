﻿#include <QtWidgets>

#include "imagedelegate.h"
#include "iconpreviewarea.h"

ImageDelegate::ImageDelegate(QObject *parent) : QItemDelegate(parent) {}

QWidget *ImageDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const {
  QComboBox *comboBox = new QComboBox(parent);
  if (index.column() == 1) {
    comboBox->addItems(IconPreviewArea::iconModelNames());
  } else if (index.column() == 2) {
    comboBox->addItems(IconPreviewArea::iconStateNames());
  }
  connect(comboBox, QOverload<int>::of(&QComboBox::activated), this,
          &ImageDelegate::emitCommitData);
  return comboBox;
}

void ImageDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const {
  QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
  if (!comboBox) {
    return;
  }
  int pos = comboBox->findText(index.model()->data(index).toString(),
                               Qt::MatchExactly);
  comboBox->setCurrentIndex(pos);
}

void ImageDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const {
  QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
  if (!comboBox) {
    return;
  }
  model->setData(index, comboBox->currentText());
}

void ImageDelegate::emitCommitData() {
  emit commitData(qobject_cast<QWidget *>(sender()));
}
