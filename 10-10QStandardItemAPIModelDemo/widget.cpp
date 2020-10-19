#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model=new QStandardItemModel(this);

    //One needs to capture the root item
    QStandardItem * rootItem=model->invisibleRootItem();

    //Defining items

    QStandardItem * europeItem = new QStandardItem("Europe");
    QStandardItem * asiaItem=new QStandardItem("Asia");
    QStandardItem * africaItem=new QStandardItem("Africa");

    QStandardItem * romaniaItem =new QStandardItem("Romania");
    QStandardItem * russiaItem =new QStandardItem("Russia");
    QStandardItem * serbiaItem =new QStandardItem("Serbia");
    QStandardItem * chinaItem =new QStandardItem("China");
    QStandardItem * indiaItem=new QStandardItem("India");
    QStandardItem * rwandaItem=new QStandardItem("Rwanda");

    QStandardItem * bucharestItem=new QStandardItem("Bucharest");
    QStandardItem * galatiItem=new QStandardItem("Galati");
    QStandardItem * constantaItem=new QStandardItem("Constanta");
    QStandardItem * moskvaItem=new QStandardItem("Moskva");
    QStandardItem * sanktPetersburgItem=new QStandardItem("Sankt Petersburg");

    //Define the tree structure

    rootItem->appendRow(africaItem);
    rootItem->appendRow(europeItem);
    rootItem->appendRow(asiaItem);


    africaItem->appendRow(rwandaItem);
    europeItem->appendRow(romaniaItem);
    europeItem->appendRow(russiaItem);
    europeItem->appendRow(serbiaItem);

    romaniaItem->appendRow(galatiItem);
    romaniaItem->appendRow(bucharestItem);
    romaniaItem->appendRow(constantaItem);
    russiaItem->appendRow(moskvaItem);
    russiaItem->appendRow(sanktPetersburgItem);


    //Set the model to the view we have in the ui widget
    ui->treeView->setModel(model);

    //Expand everything in the tree view
    ui->treeView->expandAll();

    QItemSelectionModel * itemSelection=ui->treeView->selectionModel() ;
    connect(itemSelection,SIGNAL(selectionChanged(QItemSelection, QItemSelection)),this, SLOT(selectionChangedSlot(QItemSelection,QItemSelection)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    qDebug()<<"Something has changed";

    QModelIndex thisIndex=ui->treeView->selectionModel()->currentIndex(); //get the model index of the selected item
    QString dataAtIndex=model->data(thisIndex,Qt::DisplayRole).toString();

    qDebug()<<dataAtIndex;
}

