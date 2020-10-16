#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString path="D:/";

    //Initialize the dirModel object
    dirModel=new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    dirModel->setRootPath(path);

    //Bind the model to a view
    ui->treeView->setModel(dirModel);



    //Initialize the fileModel object
    fileModel=new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(path);

    //Bind the model to a view
    ui->listView->setModel(fileModel);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_treeView_clicked(const QModelIndex &index)
{
    /* *** QFileInfo QFileSystemModel::fileInfo(const QModelIndex &index) const *** */
    /* *** Returns the QFileInfo for the item stored in the model under the given index. *** */

    QString myPath=dirModel->fileInfo(index).absoluteFilePath();
    qDebug()<<"The path for the selected item is :"<<myPath;


    /* *** QModelIndex QFileSystemModel::setRootPath(const QString &newPath)
    Sets the directory that is being watched by the model to newPath by installing a file system watcher on it.
    Any changes to files and directories within this directory will be reflected in the model.
    * *** */

    /* *** void QAbstractItemView::setRootIndex(const QModelIndex &index)
    Sets the root item to the item at the given index.
    * ***/

    ui->listView->setRootIndex(fileModel->setRootPath(myPath));

}
