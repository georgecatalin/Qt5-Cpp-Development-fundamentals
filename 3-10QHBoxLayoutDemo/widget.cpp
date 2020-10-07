#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    /*

    //Define the layout
    QHBoxLayout * hLayout=new QHBoxLayout();

    //Add widgets to the layout
    hLayout->addWidget(ui->oneButton);
    hLayout->addWidget(ui->twoButton);
    hLayout->addWidget(ui->threeButton);
    hLayout->addWidget(ui->fourButton);
    hLayout->addWidget(ui->fiveButton);

    //Set the layout to the UI
    setLayout(hLayout);

    */

}

Widget::~Widget()
{
    delete ui;
}

