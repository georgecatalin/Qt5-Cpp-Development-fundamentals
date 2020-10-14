#include "customdialog.h"
#include "ui_customdialog.h"

customDialog::customDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customDialog)
{
    ui->setupUi(this);

    /* *** This is the manner of applying style sheets to the widget itself *** */
    ui->pushButton->setStyleSheet("QPushButton {background-color:white;color:green}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color:yellow;color:blue}");
}

customDialog::~customDialog()
{
    delete ui;
}
