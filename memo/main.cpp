#include "mainwindow.hpp"
#include <QApplication>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextEdit text_edit;
    text_edit.show();

    return app.exec();
}
