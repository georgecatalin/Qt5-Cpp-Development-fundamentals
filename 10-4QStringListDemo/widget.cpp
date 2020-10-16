#include "widget.h"
#include "ui_widget.h"

/* *** The QStringListModel class provides a model that supplies strings to views. *** */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //initialize model
    listModel=new QStringListModel(this);

    QStringList myList;

    myList<<"Renault"<<"Dacia"<<"Peugeout"<<"Citroen"<<"Audi";

    /* *** void QStringListModel::setStringList(const QStringList &strings)
     Sets the model's internal string list to strings. The model will notify any attached views that its underlying
     data has changed.
    *** */

    listModel->setStringList(myList);

    ui->listView->setModel(listModel);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_getDataButton_clicked()
{
    QStringList getList=listModel->stringList();
    qDebug()<<"The data stored in the stringlist is: "<<getList;
}
