#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    /*
    //Using String Notation to mark the signal and slot connection
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), ui->progressBar,SLOT(setValue(int)));
    */

    /*
    //Using Functor notation: normal slots
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->progressBar,&QProgressBar::setValue);
    */

    //Using Functor notation: lambda notation
    connect(ui->horizontalSlider,&QSlider::valueChanged,[=]()
    {
        ui->progressBar->setValue(ui->horizontalSlider->value());
    });
}

Widget::~Widget()
{
    delete ui;
}

