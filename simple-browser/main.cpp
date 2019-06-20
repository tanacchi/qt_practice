#include "simplebrowser.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleBrowser w;
    w.show();

    return a.exec();
}
