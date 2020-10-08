#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Mark the list widget as multi selection
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addItemButton_clicked()
{
    ui->listWidget->addItem("myNewItem");
}

void Widget::on_deleteItemButton_clicked()
{
    //Delete item in ListWidget by means of takeItem()
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_selectedItemsButton_clicked()
{
    //Get the list of selected items in the list widget
    QList<QListWidgetItem *> myList=ui->listWidget->selectedItems();

    //Display the selected items on the screen
    for(int i=0;i<myList.count();i++)
    {
        qDebug()<<"The selected element is :"<<myList.at(i)->text()<<" at row: "<< ui->listWidget->row(myList.at(i));
    }
}
