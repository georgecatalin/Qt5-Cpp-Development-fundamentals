#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Add elements to the combo box programatically
    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Moon");

    //Make the combo box editable
    ui->comboBox->setEditable(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureValueButton_clicked()
{
    qDebug()<<"The currently selected element in the combo box is at index "<<QString::number(ui->comboBox->currentIndex())<<" and it is "<<ui->comboBox->currentText();
}

void Widget::on_setValueButton_clicked()
{
    ui->comboBox->setCurrentIndex(3);
}

void Widget::on_getValuesButton_clicked()
{
    qDebug()<<"There are currently "<<QString::number(ui->comboBox->count())<<" elements in the combo box. They are: ";

    for(int i=0;i<ui->comboBox->count();i++)
    {
        qDebug()<<"Index "<<QString::number(i)<<" element "<<ui->comboBox->itemText(i);
    }
}
