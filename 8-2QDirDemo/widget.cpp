#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_chooseDirButton_clicked()
{
    QString dirName=QFileDialog::getExistingDirectory(this,"Choose directory");

    if (dirName.isEmpty())
    {
        return;
    }

    ui->lineEdit->setText(dirName);
}

void Widget::on_createDirButton_clicked()
{
    //Create a directory if it does not exist, if it exists already, then do nothing

    QString path=ui->lineEdit->text();

    if (path.isEmpty())
    {
        return;
    }

    QDir dir(path);
    if (!dir.exists())
    {
        //create the directory
        if(dir.mkpath(path))
        {
            QMessageBox::information(this, "Success","Directory created successfully.");
        }
        else
        {
            QMessageBox::information(this,"Failure","Directory not created due to failure.");
        }
    }
    else
    {
        //do nothing as directory already exists
        QMessageBox::information(this,"Message","Directory already exists.");
    }


}

void Widget::on_existsDirButton_clicked()
{
    QString path=ui->lineEdit->text();

    if (path.isEmpty())
    {
        return;
    }

    QDir dir(path);

    if (dir.exists())
    {
      QMessageBox::information(this,"Yes","The selected directory already exists");
    }
    else
    {
        QMessageBox::information(this,"No","The directory does not exist");
    }
}

void Widget::on_dirOrFileButton_clicked()
{
  QFileInfo fileInfo(ui->listWidget->currentItem()->text());

  if (fileInfo.isDir())
  {
      QMessageBox::information(this,"Directory","Alligator, this is a directory.");
  }
  else if(fileInfo.isFile())
  {
      QMessageBox::information(this,"File","Alligator, this is a file");
  }
  else
  {
      QMessageBox::information(this,"Uncertain", "Bro, I do not know what you are telling me.");
  }

}

void Widget::on_folderContentButton_clicked()
{
   ui->listWidget->clear();

  QString dirPath=ui->lineEdit->text();

  if (dirPath.isEmpty())
  {
    return;
  }

  QDir dir(dirPath);
  QList<QFileInfo> myList=dir.entryInfoList();

  for(QFileInfo itemInList : myList)  //same syntax of foreach() in C++ and Java
  {
      QString prefix;

      if (itemInList.isDir())
      {
          prefix="DIRECTORY :";
      }

      if (itemInList.isFile())
      {
          prefix="FILE :";
      }

     // ui->listWidget->addItem(prefix+" "+itemInList.absoluteFilePath());
      ui->listWidget->addItem(itemInList.absoluteFilePath());
  }


}
