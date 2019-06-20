#include "simplebrowser.hpp"
#include <QApplication>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleBrowser w;

    w.load(QUrl("https://google.com"));
    w.show();

    return a.exec();
}
