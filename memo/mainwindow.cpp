#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QMenuBar>

MainWindow::MainWindow(): QMainWindow(nullptr)
  , text_edit_ptr_{std::make_unique<QTextEdit>()}
  , load_action_ptr_{std::make_unique<QAction>(tr("Load"))}
  , save_action_ptr_{std::make_unique<QAction>(tr("Save"))}
  , exit_action_ptr_{std::make_unique<QAction>(tr("Exit"))}
  , file_menu_ptr_{menuBar()->addMenu(tr("File"))}
{
  connect(load_action_ptr_.get(), SIGNAL(triggered()), this, SLOT(load()));
  connect(save_action_ptr_.get(), SIGNAL(triggered()), this, SLOT(save()));
  connect(exit_action_ptr_.get(), SIGNAL(triggered()), qApp, SLOT(quit()));

  file_menu_ptr_->addAction(load_action_ptr_.get());
  file_menu_ptr_->addAction(save_action_ptr_.get());
  file_menu_ptr_->addSeparator();
  file_menu_ptr_->addAction(exit_action_ptr_.get());

  setCentralWidget(text_edit_ptr_.get());
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
  QString file_name
      = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt);; C++ files (*.cpp *.hpp)"));
  if (!file_name.isEmpty())
  {
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::critical(this, "Error", tr("Could not open file."));
      return;
    }
    QTextStream in(&file);
    text_edit_ptr_->setText(in.readAll());
    file.close();
  }
}

void MainWindow::save()
{
  QString file_name
      = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text files (*txt);; C++ files (*.cpp *.hpp)"));
  if (!file_name.isEmpty())
  {
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly))
    {
      QTextStream ostream(&file);
      ostream << text_edit_ptr_->toPlainText();
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
