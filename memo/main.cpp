#include "mainwindow.hpp"
#include <QApplication>
#include <QTextEdit>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextEdit* text_edit = new QTextEdit;
    QPushButton* quit_button = new QPushButton{"&Qiut"};

    QObject::connect(quit_button, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(text_edit);
    layout->addWidget(quit_button);

    QWidget window;
    window.setLayout(layout);

    window.show();

    return app.exec();
}
