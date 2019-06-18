#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <memory>

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
  std::unique_ptr<QTextEdit> text_edit_ptr_;
  std::unique_ptr<QAction> load_action_ptr_;
  std::unique_ptr<QAction> save_action_ptr_;
  std::unique_ptr<QAction> exit_action_ptr_;
  std::unique_ptr<QMenu> file_menu_ptr_;

};

#endif // MAINWINDOW_HPP
