#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup> //to make them exclusive, checkboxes need to be included in a buttongroup

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup * buttonGroup=new QButtonGroup(this);

    buttonGroup->addButton(ui->windowsCheckBox);
    buttonGroup->addButton(ui->macCheckBox);
    buttonGroup->addButton(ui->linuxCheckBox);

    buttonGroup->setExclusive(true);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_windowsCheckBox_toggled(bool checked)
{
    if(checked)
    {
        qDebug()<<"Windows checkbox is checked.";
    }
    else
    {
        qDebug()<<"Windows checkbox is unchecked";
    }

}

void Widget::on_beerCheckBox_toggled(bool checked)
{
    if (checked)
    {
        qDebug()<<"Beer checkbox is checked.";
    }
    else
    {
        qDebug()<<"Beer checkbox is unchecked.";
    }
}

void Widget::on_aRadioButton_toggled(bool checked)
{
    if (checked)
    {
     qDebug()<<"A radiobutton is checked";
    }
    else
    {
     qDebug()<<"A radiobutton is not checked.";
    }
}

void Widget::on_grabDataButton_clicked()
{
    if(ui->windowsCheckBox->isChecked())
    {
        qDebug()<<"Windows CheckBox is checked.";
    }
    else
    {
        qDebug()<<"Windows CheckBox is unchecked";
    }

    if(ui->beerCheckBox->isChecked())
    {
        qDebug()<<"Beer Checkbox is checked";
    }
    else
    {
        qDebug()<<"Beer CheckBox is unchecked";
    }

    if(ui->aRadioButton->isChecked())
    {
        qDebug()<<"A radiobutton is checked.";
    }
    else
    {
        qDebug()<<"A radiobutton is not checked";
    }
}

void Widget::on_setStatusButton_clicked()
{
    //this is an exclusive checkbox, won't be made false unless someother takes true in the same group
    if (ui->windowsCheckBox->isChecked())
    {
        ui->windowsCheckBox->setChecked(false);
    }
    else
    {
        ui->windowsCheckBox->setChecked(true);
    }

    //this is a non exclusive checkbox, it does not matter
    if(ui->beerCheckBox->isChecked())
    {
        ui->beerCheckBox->setChecked(false);
    }
    else
    {
        ui->beerCheckBox->setChecked(true);
    }
}
