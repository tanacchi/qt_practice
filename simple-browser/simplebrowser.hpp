#ifndef SIMPLEBROWSER_HPP
#define SIMPLEBROWSER_HPP

#include <QWidget>

namespace Ui {
class SimpleBrowser;
}

class SimpleBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleBrowser(QWidget *parent = nullptr);
    ~SimpleBrowser();

private:
    Ui::SimpleBrowser *ui;
};

#endif // SIMPLEBROWSER_HPP
