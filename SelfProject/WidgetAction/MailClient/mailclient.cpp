#include <QIcon>
#include <QMenuBar>
#include <QSettings>
#include <QSplitter>
#include <QStatusBar>
#include <QTextEdit>
#include <QTreeWidget>

#include "mailclient.h"

MailClient::MailClient(QWidget *parent) : QMainWindow(parent) {
  QIcon folderIcon(style()->standardPixmap(QStyle::SP_DirClosedIcon));
  QIcon trashIcon(style()->standardPixmap(QStyle::SP_FileIcon));

  QStringList folderLabels;
  folderLabels << tr("Folders");

  foldersTreeWidget = new QTreeWidget;
  foldersTreeWidget->setHeaderLabels(folderLabels);
  addFolder(folderIcon, tr("Inbox"));
  addFolder(folderIcon, tr("Outbox"));
  addFolder(folderIcon, tr("Sent"));
  addFolder(trashIcon, tr("Trash"));

  QStringList messageLabels;
  messageLabels << tr("Subject") << tr("Sender") << tr("Date");

  messageTreeWidget = new QTreeWidget;
  messageTreeWidget->setHeaderLabels(messageLabels);
  addMessage(tr("Happy New Year!"), tr("Grace K. <grace@software-inc.com>"),
             tr("2006-12-31"));
  addMessage(tr("Radically new concept!"),
             tr("Grace K. <grace@software-inc.com>"), tr("2006-12-22"));
  addMessage(tr("Accounts"), tr("pascale@nospam.com"), tr("2006-12-31"));
  addMessage(tr("Expenses"), tr("Joe Bloggs <joe@bloggs.com>"),
             tr("2006-12-25"));
  addMessage(tr("Re: Expenses"), tr("Andy <andy@nospam.com>"),
             tr("2007-01-02"));
  addMessage(tr("Re: Accounts"), tr("Joe Bloggs <joe@bloggs.com>"),
             tr("2007-01-03"));
  addMessage(tr("Re: Accounts"), tr("Andy <andy@nospam.com>"),
             tr("2007-01-03"));
  messageTreeWidget->resizeColumnToContents(0);
  messageTreeWidget->resizeColumnToContents(1);

  textEdit = new QTextEdit;
  textEdit->setReadOnly(true);
  textEdit->setHtml(
		    "<table bolder=0>"
		    "<tr><td align=right><b>Subject:</b>"
		    "<td><p>Happy New Year!"
		    "<tr><td align=right><b>Date:</b>"
		    "<td><p>Sun, 31 Dec 2006"
		    "<tr><td align=right><b>From:</b>"
		    "<td><p>Grace K. &lt;grace@software-inc.com&gt;"
		    "<tr><td align=right><b>To:</b>"
		    "<td>all@software-inc.com"
		    "</table>"
		    "<br>I want to seize this occasion to thank "
		    "everybody for the year that has gone, and want "
		    "to wish you the best for next year. It has been "
		    "a pleasure to work with you all on the Hawk "
		    "project, and I'm sure we'll get concrete "
		    "results shortly."
		    "<br><br>Happy New Year!"
		    "<br>--Grace");

  menuBar()->addMenu(tr("&File"));
  menuBar()->addMenu(tr("&Edit"));
  menuBar()->addMenu(tr("&View"));
  menuBar()->addMenu(tr("F&older"));
  menuBar()->addMenu(tr("&Message"));
  menuBar()->addMenu(tr("&Settings"));
  menuBar()->addMenu(tr("&Help"));
  statusBar()->showMessage(tr("No new messages on server"));

  rightSplitter = new QSplitter(Qt::Vertical);
  rightSplitter->addWidget(messageTreeWidget);
  rightSplitter->addWidget(textEdit);
  rightSplitter->setStretchFactor(1, 1);

  mainSplitter = new QSplitter(Qt::Horizontal);
  mainSplitter->addWidget(foldersTreeWidget);
  mainSplitter->addWidget(rightSplitter);
  mainSplitter->setStretchFactor(1, 1);
  setCentralWidget(mainSplitter);

  setWindowTitle(tr("Mail Client"));
  readSettings();
}

MailClient::~MailClient() {}

void MailClient::addFolder(const QIcon &icon, const QString &name) {
  QTreeWidgetItem *root;
  if (foldersTreeWidget->topLevelItemCount() == 0) {
    root = new QTreeWidgetItem(foldersTreeWidget);
    root->setText(0, tr("Mail"));
    foldersTreeWidget->setItemExpanded(root, true);
  } else {
    root = foldersTreeWidget->topLevelItem(0);
  }

  QTreeWidgetItem *newItem = new QTreeWidgetItem(root);
  newItem->setText(0, name);
  newItem->setIcon(0, icon);

  if (!foldersTreeWidget->currentItem()) {
    foldersTreeWidget->setCurrentItem(newItem);
  }
}

void MailClient::addMessage(const QString &subject, const QString &from,
                            const QString &date) {
  QTreeWidgetItem *newItem = new QTreeWidgetItem(messageTreeWidget);
  newItem->setText(0, subject);
  newItem->setText(1, from);
  newItem->setText(2, date);

  if (!messageTreeWidget->currentItem()) {
    messageTreeWidget->setCurrentItem(newItem);
  }
}

void MailClient::readSettings() {
  QSettings settings("Software Inc.", "Mail Client");

  settings.beginGroup(tr("mainWindow"));
  restoreGeometry(settings.value("geometry").toByteArray());
  mainSplitter->restoreState(settings.value("mainSplitter").toByteArray());
  rightSplitter->restoreState(settings.value("rightSplitter").toByteArray());
  settings.endGroup();
}

void MailClient::writeSettings() {
  QSettings settings("Software Inc.", "Mail Client");

  settings.beginGroup("mainWindow");
  settings.setValue("geometry", saveGeometry());
  settings.setValue("mainSplitter", mainSplitter->saveState());
  settings.setValue("rightSplitter", rightSplitter->saveState());
  settings.endGroup();
}
