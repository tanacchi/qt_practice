#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow()
  : QWidget(nullptr)
{
  text_edit_ = new QTextEdit();
  quit_button_ = new QPushButton(tr("Quit"));
  connect(quit_button_, SIGNAL(clicked()), this, SLOT(quit()));
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(text_edit_);
  layout->addWidget(quit_button_);

  setLayout(layout);

  setWindowTitle(tr("Notepad"));
}

void MainWindow::quit()
{
  QMessageBox messageBox;
  messageBox.setWindowTitle(tr("Notepad"));
  messageBox.setText(tr("Do you really want to quit?"));
  messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  messageBox.setDefaultButton(QMessageBox::No);
  if (messageBox.exec() == QMessageBox::Yes)
      qApp->quit();
}
