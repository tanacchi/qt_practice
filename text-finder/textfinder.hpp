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

private:
    Ui::TextFinder *ui;
};

#endif // TEXTFINDER_HPP
