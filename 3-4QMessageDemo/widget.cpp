#include "widget.h"
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton * myButton = new QPushButton(this);
    myButton->setText("Click me");
    myButton->move(200,200);

    connect(myButton,&QPushButton::clicked,[=]()
    {
        /*
        //This is the hard way
        QMessageBox message;
        message.setMinimumSize(300,400);
        message.setWindowTitle("This is the title of the window");
        message.setText("This is the text.");
        message.setInformativeText("Do you want to do something about it?");
        message.setIcon(QMessageBox::Critical);
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int returnChoice=message.exec();

        */

        /*
        //This is the easy way, by using static methods
        //Critical Static Method
        int returnChoice=QMessageBox::critical(this,"Message Title","Do you want to do something about this?",QMessageBox::Ok | QMessageBox::Cancel);
        */

        //Information static Method
        //int returnChoice=QMessageBox::information(this,"Message Title","Do you want to do something about this?",QMessageBox::Ok | QMessageBox::Cancel);

        //Question static Method
        //int returnChoice=QMessageBox::question(this,"Message Title","Do you want to do something about this?", QMessageBox::Ok | QMessageBox::Cancel);

        //Warning static Method
        int returnChoice=QMessageBox::warning(this,"Message Title","Do you want to do something about this?", QMessageBox::Ok | QMessageBox::Cancel);

        if(returnChoice==QMessageBox::Ok)
        {
            qDebug()<<"User has clicked OK";
        }

        if(returnChoice==QMessageBox::Cancel)
        {
            qDebug()<<"User has clicked Cancel";
        }

    });
}

Widget::~Widget()
{
}

