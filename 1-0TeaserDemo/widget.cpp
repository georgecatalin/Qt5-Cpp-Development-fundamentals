#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

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
    qDebug()<<"Submitting data...";
    qDebug()<<"First Name is :"<< ui->firstNameLineEdit->text();
    qDebug()<<"Last Name is :"<< ui->lastNameLineEdit->text();
    qDebug()<<"Message is :"<< ui->messageLineEdit->toPlainText();
}
