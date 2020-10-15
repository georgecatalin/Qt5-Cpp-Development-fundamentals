#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model=new QFileSystemModel(this);

    parentIndex=model->setRootPath("C:/Program Files");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    int rows=model->rowCount(parentIndex);
    qDebug()<<"The number of rows of the model is :"<<QString::number(rows);

    for (int i=0;i<rows;i++)
    {
        QModelIndex index=model->index(i,0,parentIndex);
        QString myData=model->data(index,Qt::DisplayRole).toString();

        qDebug()<<"Data member is ["<< QString::number(i)<<"]"<<myData;

    }
}
