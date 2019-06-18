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
  QString file_name = QFileDialog::getOpenFileName(this,
                                                   tr("Open file"),
                                                   "",
                                                   tr("Text files (*.txt);; C++ files (*.cpp *.hpp)"));
  if (!file_name.isEmpty())
  {
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::critical(this, "Error", tr("Could not open file."));
      return;
    }
    QTextStream in(&file);
    text_edit_->setText(in.readAll());
    file.close();
  }
}

void MainWindow::save()
{
  QString file_name = QFileDialog::getSaveFileName(this,
                                                   tr("Save File"),
                                                   "",
                                                   tr("Text files (*txt);; C++ files (*.cpp *.hpp)"));
  if (!file_name.isEmpty())
  {
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly))
    {
      QTextStream ostream(&file);
      ostream << text_edit_->toPlainText();
      ostream.flush();
      file.close();
    }
    else
    {
      QMessageBox::critical(this, "Error", tr("Could not save file."));
      return;
    }
  }
}
