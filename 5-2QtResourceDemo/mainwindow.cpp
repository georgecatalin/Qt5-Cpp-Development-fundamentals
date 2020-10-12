#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/new/images/images/code-blocks-icon.png");
    ui->label->setPixmap(pix.scaled(200,200));
}

MainWindow::~MainWindow()
{
    delete ui;
}

