#include "widget.hpp"
#include "ui_widget.h"

#include <QUrl>
#include <QWebEngineHttpRequest>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    managar{new QNetworkAccessManager()}
{
    ui->setupUi(this);
    connect(managar, &QNetworkAccessManager::finished, this, &Widget::response_callback);
}

Widget::~Widget()
{
    delete ui;
    delete managar;
}

void Widget::on_pushButton_clicked()
{
  QUrl url("https://tanacchi-birdbrains.herokuapp.com/line");
  request.setUrl(url);
  managar->get(request);
}

void Widget::response_callback(QNetworkReply* reply)
{
  ui->textBrowser->setText(reply->readAll());
}
