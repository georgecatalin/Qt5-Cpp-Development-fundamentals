#include "widget.h"
#include "ui_widget.h"
#include "customdialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    customDialog * myDialog =new customDialog(this);

    /* ***  This is the manner of applying style sheets in the container *** */
    //myDialog->setStyleSheet("QPushButton{background-color:blue;color:yellow}");

    myDialog->exec();
}
