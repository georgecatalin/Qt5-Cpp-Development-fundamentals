#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize tree model
    treeModel =new QStandardItemModel(this);
    QModelIndex parentIndex=QModelIndex();

    for (int i=0;i<5;i++)
    {
        //qDebug()<<"current item is "<<QString::number(i);

        /* *** bool QStandardItemModel::insertRow(int row, const QModelIndex &parent = QModelIndex())
        Inserts a single row before the given row in the child items of the parent specified.
        Returns true if the row is inserted; otherwise returns false.
        * *** */

        treeModel->insertRow(0,parentIndex);

        /* *** bool QStandardItemModel::insertColumn(int column, const QModelIndex &parent = QModelIndex())
       Inserts a single column before the given column in the child items of the parent specified.
        Returns true if the column is inserted; otherwise returns false.
        * *** */

        treeModel->insertColumn(0,parentIndex);

        parentIndex=treeModel->index(0,0,parentIndex);

        QString value=QString("number %0.").arg(i);

        treeModel->setData(parentIndex,QVariant::fromValue(value));


    }

     ui->treeView->setModel(treeModel);


    //Initialize table model
    tableModel=new QStandardItemModel(this);
    tableModel->setRowCount(3);
    tableModel->setColumnCount(5);

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<5;j++)
        {
            QString myData=QString("row %0, column %1").arg(i).arg(j);
            QModelIndex index=tableModel->index(i,j,QModelIndex());

            /* *** void QStandardItem::setData(const QVariant &value, int role = Qt::UserRole + 1)
            Sets the item's data for the given role to the specified value.
            * ***/

            tableModel->setData(index, QVariant::fromValue(myData));

            ui->tableView->setModel(tableModel);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_tableView_clicked(const QModelIndex &index)
{
    QString myData=tableModel->data(index,Qt::DisplayRole).toString();

    qDebug()<<"The selected content of the cell is: "<<myData;
}
