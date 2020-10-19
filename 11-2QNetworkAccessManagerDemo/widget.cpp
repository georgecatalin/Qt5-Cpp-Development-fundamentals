#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>
#include <QDebug>

/* ** The QNetworkAccessManager class allows the application to send network requests and receive replies. ** */


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //define the objects
    networkAccessManager=new QNetworkAccessManager(this);
    networkReply=nullptr;
    byteArray=new QByteArray(); //The QByteArray class provides an array of bytes.

    //Define request
    QNetworkRequest myRequest;
    myRequest.setUrl(QUrl("http://www.rt.com")); //read source page of "Russia Today" website

    //Send the request through the network
    networkReply=networkAccessManager->get(myRequest);

    connect(networkReply,&QIODevice::readyRead,this,&Widget::readToRead);
    connect(networkReply,&QNetworkReply::finished,this, &Widget::readFinished);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readToRead()
{
    qDebug()<<"Something is being read";
    byteArray->append(networkReply->readAll());
}

void Widget::readFinished()
{
    /* ***
     * QNetworkReply::NetworkError QNetworkReply::error() const
       Returns the error that was found during the processing of this request.
       If no error was found, returns NoError.
     *** */

    if (networkReply->error())
    {
        /* *** QString QIODevice::errorString() const
        Returns a human-readable description of the last device error that occurred.
        *** */


        qDebug()<<"Ooops...there was an error"<<networkReply->errorString();
    }
    else
    {
        ui->textEdit->setPlainText(QString(* byteArray));
    }

}

