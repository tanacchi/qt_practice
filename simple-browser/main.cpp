#include "simplebrowser.hpp"
#include <QApplication>
#include <QWebEngineView>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleBrowser w;
    QWebEngineView* view = new QWebEngineView(&w);

    view->load(QUrl("https://google.com"));
    view->resize(400, 600);
    view->show();

    w.show();

    return a.exec();
}
