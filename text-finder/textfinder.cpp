#include "textfinder.hpp"
#include "ui_textfinder.h"

#include <QFile>
#include <QTextStream>

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    load_text_file();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_pushButton_clicked()
{
    QString search_str = ui->lineEdit->text();
    ui->textEdit->find(search_str, QTextDocument::FindWholeWords);
}

void TextFinder::load_text_file()
{
    QFile input_file(":/input.txt");
    input_file.open(QIODevice::ReadOnly);

    QTextStream istream(&input_file);
    QString input_str = istream.readAll();
    input_file.close();

    ui->textEdit->setPlainText(input_str);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
