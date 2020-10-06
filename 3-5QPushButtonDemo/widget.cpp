#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //This is clicked signal
    QFont thisFont("Times",20, QFont::Bold);
    QPushButton * myButton=new QPushButton("Click me",this);

    myButton->setMinimumSize(200,100);
    myButton->setFont(thisFont);

    connect(myButton,&QPushButton::clicked,[=]()
    {
        qDebug()<<"Button is clicked.";
    });

    //This is pressed and released signals
    QPushButton * myButton2=new QPushButton("Click me",this);

    myButton2->setMinimumSize(200,100);
    myButton2->move(205,0);
    myButton2->setFont(thisFont);

    connect(myButton2,&QPushButton::pressed,[=]()
    {
        qDebug()<<"Button is pressed.";
    });

    connect(myButton2,&QPushButton::released,[=]()
    {
     qDebug()<<"Button is released.";

    });

}

Widget::~Widget()
{
}

