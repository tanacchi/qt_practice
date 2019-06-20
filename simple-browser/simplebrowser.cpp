#include "simplebrowser.hpp"
#include "ui_simplebrowser.h"

SimpleBrowser::SimpleBrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleBrowser)
{
    ui->setupUi(this);
}

SimpleBrowser::~SimpleBrowser()
{
    delete ui;
}
