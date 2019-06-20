#include "widget.hpp"
#include "ui_widget.h"

#include <QUrl>
#include <QWebEngineHttpRequest>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
  QUrl url("https://tanacchi-birdbrains.herokuapp.com/line");
  QNetworkRequest request(url);
  QNetworkAccessManager manager;
  reply = manager.get(request);
  connect(reply, &QNetworkReply::finished, this, &Widget::response_callback);
}

void Widget::response_callback()
{
  std::cout << reply->size() << std::endl;
  ui->textBrowser->setText(reply->readAll());
}
