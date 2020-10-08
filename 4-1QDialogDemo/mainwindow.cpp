#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_showInfoButton_clicked()
{
    InfoDialog * infoDialog=new InfoDialog(this);

    int returnResult=infoDialog->exec();


    if (returnResult==QDialog::Accepted)
    {
        qDebug()<<"Dialog was accepted.";
    }
    else
    {
        qDebug()<<"Dialog was rejected.";
    }

}
