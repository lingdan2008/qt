#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QTableWidget>

class Cell;
class SpreadsheetCompare;

class Spreadsheet : public QTableWidget {
 public:
  Spreadsheet(QWidget *parent = 0);

  bool autoRacalculate() const { return autoRecalc; }
  QString currentLocation() const;
  QString currentFormula() const;
  QTableWidgetSelectionRange selectedRange() const;
  void clear();
  bool readFile(const QString &fileName);
  bool writeFile(const QString &fileName);
  bool sort(const SpreadsheetCompare &compare);

 public
slots:
  void cut();
  void copy();
  void paste();
  void del();
  void selectCurrentRow();
  void selectCurrentColumn();
  void recalculate();
  void setAutoRecalculate(bool recalc);
  void findNext(const QString &str, Qt::CaseSensitivity cs);
  void findPrevious(const QString &str, Qt::CaseSensitivity cs);

signals:
  void modified();

 private
slots:
  void somethingChanged();

 private:
  enum {
    MagicNumber = 0x7F51C883,
    RowCount = 999,
    ColumnCount = 26
  };

  Cell *cell(int row, int column) const;
  QString text(int row, int column) const;
  QString formula(int row, int column) const;
  void setFormula(int row, int column, const QString &formula);

  bool autoRecalc;
};

class SpreadsheetCompare {
 public:
  bool operator()(const QString &row1, const QString &row2) const;

  enum {
    KeyCount = 3
  };
  int keys[KeyCount];
  bool ascending[KeyCount];
};

#endif  // SPREADSHEET_H
