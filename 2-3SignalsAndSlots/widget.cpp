#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*
    //This is String Notation to mark the connection Signal and Slots
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(changeText()));
    */

    /*
    //This is the functor notation: Regular slots
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::changeText);
    */

    //This is the functor notation: Lambda
    connect(ui->pushButton,&QPushButton::clicked,[=]()
    {
        ui->label->setText("Lambda");
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeText()
{
    qDebug("User has clicked the button.");
    ui->label->setText("User has clicked the button");
}

