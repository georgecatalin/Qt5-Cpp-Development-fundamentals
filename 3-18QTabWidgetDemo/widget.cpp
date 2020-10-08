#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //How to add a new tab widget programatically

    /* *** Step 1. Define the Widget *** */
    QWidget * myWidget=new QWidget(this);

    /* *** Declare the layout *** */
    QVBoxLayout * vLayout=new QVBoxLayout();

    /* *** Add elements to the layout *** */
    vLayout->addWidget(new QPushButton("button 1", this));
    vLayout->addWidget(new QPushButton("button 2",this));
    vLayout->addWidget(new QPushButton("button 3", this));

    QPushButton * button4=new QPushButton("button 4", this);
    vLayout->addWidget(button4);
    connect(button4,&QPushButton::clicked,[=]()
    {
        qDebug()<<"Button 4 of the custom tab has been clicked.";
    });

    //Set the layout
    myWidget->setLayout(vLayout);

    //Add the new tab
   // ui->tabWidget->addTab(myWidget,"Tab 4");

    /* *** when using insertTab() function, one can specify the position of the tab */
    ui->tabWidget->insertTab(1,myWidget,"Tab custom");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    qDebug()<<"Button in tab1 was pressed.";
}
