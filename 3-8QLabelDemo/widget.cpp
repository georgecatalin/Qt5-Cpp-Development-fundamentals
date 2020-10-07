#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Ziz Stories");

    ui->dusterTextLabel->move(10,30);

    //add image to image label
    ui->imageTextLabel->move(0,80);

    QPixmap imagePixmap(":/new/images/images/Zizou.jpg");
    ui->imageTextLabel->setPixmap(imagePixmap.scaled(800,800));
}

Widget::~Widget()
{
    delete ui;
}

