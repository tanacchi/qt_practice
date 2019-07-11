#ifndef SIMPLEBROWSER_HPP
#define SIMPLEBROWSER_HPP

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class SimpleBrowser;
}

class SimpleBrowser : public QWebEngineView
{
    Q_OBJECT

public:
    explicit SimpleBrowser(QWidget *parent = nullptr);
    ~SimpleBrowser();

private:
    Ui::SimpleBrowser *ui;
};

#endif // SIMPLEBROWSER_HPP
