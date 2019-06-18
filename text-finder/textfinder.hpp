#ifndef TEXTFINDER_HPP
#define TEXTFINDER_HPP

#include <QWidget>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = nullptr);
    ~TextFinder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TextFinder *ui;

    void load_text_file();
};

#endif // TEXTFINDER_HPP
