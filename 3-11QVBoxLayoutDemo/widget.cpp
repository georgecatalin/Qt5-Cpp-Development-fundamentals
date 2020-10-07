#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*

    //Define QVBoxLayout
    QVBoxLayout * vLayout=new QVBoxLayout();

    //Add widgets to the layout
    vLayout->addWidget(ui->oneButton);
    vLayout->addWidget(ui->twoButton);
    vLayout->addWidget(ui->threeButton);
    vLayout->addWidget(ui->fourButton);
    vLayout->addWidget(ui->fiveButton);

    //Set the layout in the UI
    setLayout(vLayout);

    */


}

Widget::~Widget()
{
    delete ui;
}

