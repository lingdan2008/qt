#ifndef EDITOR_H
#define EDITOR_H

#include <QTextEdit>

class Editor : public QTextEdit {
  Q_OBJECT

 public:
  Editor(QWidget *parent = 0);

  void newFile();
  bool save();
  bool saveAs();
  QSize sizeHint() const;
  QAction *windowMenuAction() const { return action; }

  static Editor *open(QWidget *parent = 0);
  static Editor *openFile(const QString &fileName, QWidget *parent = 0);

 private:
  bool okToContinue();
  bool saveFile(const QString &fileName);
  void setCurrentFile(const QString &fileName);
  bool readFile(const QString &fileName);
  bool writeFile(const QString &fileName);
  QString strippedName(const QString *fullFileName);

  QString curFile;
  bool isUntitled;
  QAction *action;
};

#endif  // EDITOR_H
