#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsRectItem *rect_item = new QGraphicsRectItem(50, 50, 100, 100);
    scene.addItem(rect_item);
    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
