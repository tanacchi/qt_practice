#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QMenuBar>

MainWindow::MainWindow()
  :  QMainWindow(nullptr)
{
  load_action_ = new QAction(tr("&Load"), this);
  save_action_ = new QAction(tr("&Save"), this);
  exit_action_ = new QAction(tr("E&xit"), this);

  connect(load_action_, SIGNAL(triggered()), this, SLOT(load()));
  connect(save_action_, SIGNAL(triggered()), this, SLOT(save()));
  connect(exit_action_, SIGNAL(triggered()), qApp, SLOT(quit()));

  file_menu_ = menuBar()->addMenu(tr("File"));
  file_menu_->addAction(load_action_);
  file_menu_->addAction(save_action_);
  file_menu_->addSeparator();
  file_menu_->addAction(exit_action_);

  text_edit_ = new QTextEdit();
  setCentralWidget(text_edit_);

  setWindowTitle(tr("Memo"));
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

void MainWindow::load()
{
}

void MainWindow::save()
{
}
