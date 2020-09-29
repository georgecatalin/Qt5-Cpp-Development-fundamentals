#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>


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
    qDebug()<<"User has clicked a button.";
    QMessageBox::information(this,"Notifier","User has clicked a button",QMessageBox::StandardButton::Ok);

}
