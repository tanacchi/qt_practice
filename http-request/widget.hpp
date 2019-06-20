#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QNetworkReply>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void response_callback();

private:
    Ui::Widget *ui;

    QNetworkReply* reply = nullptr;
};

#endif // WIDGET_HPP
