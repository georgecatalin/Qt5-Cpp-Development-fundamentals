#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_showInfoButton_clicked()
{
    infodialog * dialog=new infodialog(this);

    connect(dialog,&QDialog::accepted,[=]()
    {
        qDebug()<<"The dialog was accepted.";
    });

    connect(dialog,&QDialog::rejected,[=]()
    {
        qDebug()<<"The dialog was rejected.";
    });

    dialog->exec();
}
