#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow();

private slots:
  void quit();
  void load();
  void save();

private:
  QTextEdit* text_edit_;
  QAction* load_action_;
  QAction* save_action_;
  QAction* exit_action_;
  QMenu* file_menu_;

};

#endif // MAINWINDOW_HPP
