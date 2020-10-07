#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Define the layout
    //QGridLayout * gLayout =new QGridLayout(this);
    QGridLayout * gLayout=new QGridLayout();


    //Add the widgets to the layout
    gLayout->addWidget(ui->oneButton,0,0);
    gLayout->addWidget(ui->twoButton,0,1);
    gLayout->addWidget(ui->threeButton,0,2,2,1);

    gLayout->addWidget(ui->fourButton,1,0);
    gLayout->addWidget(ui->fiveButton,1,1);

    gLayout->addWidget(ui->sevenButton,2,0,1,2);
    gLayout->addWidget(ui->nineButton,2,2);


    //Set the layout explicitly
    /* if the layout is defined with the parent like  QGridLayout * gLayout =new QGridLayout(this); there is no need to set it out explicitly */
    setLayout(gLayout);

}

Widget::~Widget()
{
    delete ui;
}

