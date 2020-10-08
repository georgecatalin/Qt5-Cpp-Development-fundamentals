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

    /*
    // This is the version of a modal dialog
    int returnResult=infoDialog->exec();

    if (returnResult==QDialog::Accepted)
    {
        QString position=infoDialog->getPosition();
        QString os=infoDialog->getFavouriteOS();
        qDebug()<<"Dialog was accepted.";

        qDebug()<<"The position is : "<<position<<" and the favourite OS is : "<<os;
        ui->labelRead->setText("The position read is: "+ position+ " and the favourite OS is:"+ os);
    }
    else
    {
        qDebug()<<"Dialog was rejected.";
    }
    */

    //This is a non modal dialog. A non modal dialog does not return any value upon its showing up, hence we have to extract the results ourselves

    connect(infoDialog,&QDialog::accepted,[=]()
    {
        QString inputPosition=infoDialog->getPosition();
        QString inputOS=infoDialog->getFavouriteOS();

        qDebug()<<"Dialog was accepted with position input: "<<inputPosition<<" and favourite OS: "<< inputOS;
        ui->labelRead->setText("The input position is "+ inputPosition+ " and the favourite OS is "+inputOS);

    });

    connect(infoDialog,&QDialog::rejected,[=]()
    {
        qDebug()<<"Dialog was rejected";
    });

    //Display the non modal dialog
    infoDialog->show();
    infoDialog->raise();
    infoDialog->activateWindow();

}
