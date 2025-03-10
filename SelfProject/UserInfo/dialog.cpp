#include <QComboBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include "QssStyle.h"
#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
  //  QssStyle::setStyle(":/myqss.qss");
  this->setWindowTitle(tr("User Information"));

  /// Left layout
  UserNameLabel = new QLabel(tr("User Name: "));
  UserNameLineEdit = new QLineEdit();

  NameLabel = new QLabel(tr("Name: "));
  NameLineEdit = new QLineEdit();

  SexLabel = new QLabel(tr("Gender: "));
  SexComboBox = new QComboBox();
  SexComboBox->addItem(tr("Male"));
  SexComboBox->addItem(tr("Female"));
  SexComboBox->addItem(tr("Other"));

  DepartmentLabel = new QLabel(tr("Department: "));
  DepartmentTextEdit = new QTextEdit();

  AgeLabel = new QLabel(tr("Age: "));
  AgeLineEdit = new QLineEdit();

  OtherLabel = new QLabel(tr("Other..."));
  OtherLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

  LeftLayout = new QGridLayout();
  LeftLayout->addWidget(UserNameLabel, 0, 0);
  LeftLayout->addWidget(UserNameLineEdit, 0, 1);

  LeftLayout->addWidget(NameLabel, 1, 0);
  LeftLayout->addWidget(NameLineEdit, 1, 1);

  LeftLayout->addWidget(SexLabel, 2, 0);
  LeftLayout->addWidget(SexComboBox, 2, 1);

  LeftLayout->addWidget(DepartmentLabel, 3, 0);
  LeftLayout->addWidget(DepartmentTextEdit, 3, 1);

  LeftLayout->addWidget(AgeLabel, 4, 0);
  LeftLayout->addWidget(AgeLineEdit, 4, 1);

  LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);
  LeftLayout->setColumnStretch(0, 1);
  LeftLayout->setColumnStretch(1, 3);

  /// right Layout
  HeadLabel = new QLabel(tr("HeadIcon: "));

  HeadIconLabel = new QLabel();
  QPixmap icon(":/userInfo.png");
  HeadIconLabel->setPixmap(icon);
  HeadIconLabel->resize(icon.width(), icon.height());

  UpdateHeadBtn = new QPushButton(tr("Update"));

  TopRightLayout = new QHBoxLayout();
  TopRightLayout->setSpacing(20);
  TopRightLayout->addWidget(HeadLabel);
  TopRightLayout->addWidget(HeadIconLabel);
  TopRightLayout->addWidget(UpdateHeadBtn);

  IntroductionLabel = new QLabel(tr("Self introduction: "));
  IntroductionTextEdit = new QTextEdit();

  RightLayout = new QVBoxLayout();
  RightLayout->setMargin(10);
  RightLayout->addLayout(TopRightLayout);
  RightLayout->addWidget(IntroductionLabel);
  RightLayout->addWidget(IntroductionTextEdit);

  /// Bottom Layout
  OkBtn = new QPushButton(tr("Ok"));
  CancelBtn = new QPushButton(tr("Cancel"));

  ButtomLayout = new QHBoxLayout();
  ButtomLayout->addStretch();
  ButtomLayout->addWidget(OkBtn);
  ButtomLayout->addWidget(CancelBtn);

  QGridLayout *mainLayout = new QGridLayout(this);
  mainLayout->setMargin(15);
  mainLayout->setSpacing(10);
  mainLayout->addLayout(LeftLayout, 0, 0);
  mainLayout->addLayout(RightLayout, 0, 1);
  mainLayout->addLayout(ButtomLayout, 1, 0, 1, 2);
  mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

Dialog::~Dialog() {}
