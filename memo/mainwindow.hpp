#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  explicit MainWindow();

private slots:
  void quit();

private:
  QTextEdit* text_edit_;
  QPushButton* quit_button_;
};

#endif // MAINWINDOW_HPP
