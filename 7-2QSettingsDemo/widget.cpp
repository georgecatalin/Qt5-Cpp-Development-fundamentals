#include "widget.h"
#include "ui_widget.h"
#include <QColorDialog>
#include <QSettings>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //initialize the elements in the QList<QColor> object at start up
    for (int i=0;i<9;i++)
    {
        myColorList.append(Qt::black);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneButton_clicked()
{
  //save the selected color
  QColor color=QColorDialog::getColor(myColorList[0],this,"Pick the color of your choice for this button");

  if (color.isValid())
  {
      myColorList[0]=color;
  }

  //set the background of the push button to the selected color
  QString css=QString("background-color: %1").arg(color.name());
  ui->oneButton->setStyleSheet(css);
}

void Widget::on_twoButton_clicked()
{
  //save the selected color
    QColor color=QColorDialog::getColor(myColorList[1],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[1]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->twoButton->setStyleSheet(css);
}

void Widget::on_threeButton_clicked()
{
    //save the selected color
    QColor color=QColorDialog::getColor(myColorList[2],this,"Pick the colour");

    if (color.isValid()) {
        myColorList[2]=color;

    }

    //set the selected colour as background
    QString css=QString("background-color: %1").arg(color.name());
    ui->threeButton->setStyleSheet(css);

}



void Widget::on_fourButton_clicked()
{
    //save the selected colour
    QColor color=QColorDialog::getColor(myColorList[3],this,"Pick your colour");

    if (color.isValid()) {
        myColorList[3]=color;
    }

    //set the selected colour as background
    QString css=QString("background-color: %1").arg(color.name());
    ui->fourButton->setStyleSheet(css);
}

void Widget::on_fiveButton_clicked()
{
    QColor color=QColorDialog::getColor(myColorList[4],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[4]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->fiveButton->setStyleSheet(css);
}


void Widget::on_sixButton_clicked()
{
    QColor color=QColorDialog::getColor(myColorList[5],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[5]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->sixButton->setStyleSheet(css);
}


void Widget::on_sevenButton_clicked()
{
    QColor color=QColorDialog::getColor(myColorList[6],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[6]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->sevenButton->setStyleSheet(css);
}

void Widget::on_eightButton_clicked()
{
    QColor color=QColorDialog::getColor(myColorList[7],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[7]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->eightButton->setStyleSheet(css);
}


void Widget::on_nineButton_clicked()
{
    QColor color=QColorDialog::getColor(myColorList[8],this,"Pick the color");

    if (color.isValid())
    {
     myColorList[8]=color;
    }

  //set the selected colour as background color
    QString css=QString("background-color: %1").arg(color.name());
    ui->nineButton->setStyleSheet(css);
}

void Widget::saveColor(QString key, QColor color)
{
    int red=color.red();
    int blue=color.blue();
    int green=color.green();

    QSettings mySettings("GeorgeCa","My Cool App");

    mySettings.beginGroup("ButtonColours");
    mySettings.setValue(key+"r", red);
    mySettings.setValue(key+"b",blue);
    mySettings.setValue(key+"g",green);
    mySettings.endGroup();
}

QColor Widget::loadColor(QString key)
{
    int red;
    int blue;
    int green;

    QSettings mySettings("GeorgeCa","My Cool App");

    mySettings.beginGroup("ButtonColours");
    red=mySettings.value(key+"r",QVariant(0)).toInt();
    blue=mySettings.value(key+"b",QVariant(0)).toUInt();
    green=mySettings.value(key+"g",QVariant(0)).toInt();
    mySettings.endGroup();

    return QColor(red,green,blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
    QColor color=loadColor(key);
    myColorList[index]=color;
    QString css=QString("background-color: %1").arg(color.name());
    button->setStyleSheet(css);
}


void Widget::on_saveColorButton_clicked()
{
    saveColor("oneButton", myColorList[0]);
    saveColor("twoButton", myColorList[1]);
    saveColor("threeButton",myColorList[2]);
    saveColor("fourButton",myColorList[3]);
    saveColor("fiveButton",myColorList[4]);
    saveColor("sixButton",myColorList[5]);
    saveColor("sevenButton",myColorList[6]);
    saveColor("eightButton",myColorList[7]);
    saveColor("nineButton",myColorList[8]);
}

void Widget::on_loadColorButton_clicked()
{
  setLoadedColor("oneButton",0,ui->oneButton);
  setLoadedColor("twoButton",1,ui->twoButton);
  setLoadedColor("threeButton",2,ui->threeButton);
  setLoadedColor("fourButton",3,ui->fourButton);
  setLoadedColor("fiveButton",4,ui->fiveButton);
  setLoadedColor("sixButton",5,ui->sixButton);
  setLoadedColor("sevenButton",6,ui->sevenButton);
  setLoadedColor("eightButton",7,ui->eightButton);
  setLoadedColor("nineButton",8,ui->nineButton);

}
