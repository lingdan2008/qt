﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  manager = new QNetworkAccessManager(this);
  connect(manager, &QNetworkAccessManager::finished, this,
          &MainWindow::replyFinished);
  manager->get(QNetworkRequest(QUrl("http://www.qter.org")));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}

void MainWindow::replyFinished(QNetworkReply *reply) {
  QString all = reply->readAll();
  ui->textBrowser->setText(all);
  reply->deleteLater();
}
