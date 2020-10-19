#include "widget.h"
#include "ui_widget.h"

/* *** note: this app retrieves JSON data from http://jsonplaceholder.typicode.com/ *** */


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , networkAccessManager(new QNetworkAccessManager(this))
    , networkReply(nullptr)
    , byteArray(new QByteArray())
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_fetchButton_clicked()
{
    //initialize the data
    const QUrl API_ENDPOINT("http://jsonplaceholder.typicode.com/posts");


  //set a request
   QNetworkRequest request;
   request.setUrl(API_ENDPOINT);

   //send the request
   networkReply=networkAccessManager->get(request);

   connect(networkReply,&QIODevice::readyRead,this,&Widget::dataReadyRead);
   connect(networkReply,&QNetworkReply::finished,this,&Widget::dataFinishedRead);



}

void Widget::dataReadyRead()
{
    qDebug()<<"Something is being read from the web...";
    byteArray->append(networkReply->readAll());
}

void Widget::dataFinishedRead()
{
    if(networkReply->error())
    {
        qDebug()<<"Ooops..there was an error..."<<networkReply->errorString();
    }
    else
    {
        qDebug()<<QString(* byteArray);

        //convert the data read from the server into JSON
        QJsonDocument document=QJsonDocument::fromJson(* byteArray);

        //what is you get an object from the server
        //QJsonDocument document=QJsonDocument::fromJson(* byteArray);
        //QJsonObject myObject=document.toVariant().toJsonObject();

        //convert the JSON Document to an array
        QJsonArray myJSONArray=document.array();

        for (int i=0;i<myJSONArray.count();i++)
        {
            QJsonObject object=myJSONArray.at(i).toObject();
            QVariantMap map=object.toVariantMap();

            QString title=map["title"].toString();

            qDebug()<<"Element title at ["<<i<<"] is  :"<<title;

            ui->listWidget->addItem("Item at "+ QString::number(i+1)+" is :"+ title);
        }
    }
}
