#include "widget.h"
#include "ui_widget.h"
#include "customtablemodel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->tableView->verticalHeader()->hide(); //this hides the vertical header column of the table
    //ui->tableView->horizontalHeader()->hide(); //this hides the horizontal header row of the table


    CustomTableModel * myCustomModel=new CustomTableModel(this);
    ui->tableView->setModel(myCustomModel);
}

Widget::~Widget()
{
    delete ui;
}

