#include "widget.h"
#include "ui_widget.h"
#include "customtablemodel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    CustomTableModel * myCustomModel=new CustomTableModel(this);
    ui->tableView->setModel(myCustomModel);
}

Widget::~Widget()
{
    delete ui;
}

