#include "infodialog.h"
#include "ui_infodialog.h"

infodialog::infodialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infodialog)
{
    ui->setupUi(this);
}

infodialog::~infodialog()
{
    delete ui;
}

void infodialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton standardButton=ui->buttonBox->standardButton(button);

    if (standardButton== QDialogButtonBox::Ok)
    {
        accept();
        qDebug()<<"The OK button was pressed.";
    }

    if (standardButton==QDialogButtonBox::Cancel)
    {
        reject();
        qDebug()<<"The CANCEL button was pressed.";
    }

    if (standardButton==QDialogButtonBox::Save)
    {
        qDebug()<<"The SAVE button was pressed.";
    }

    if (standardButton==QDialogButtonBox::SaveAll)
    {
        qDebug()<<"The SAVEALL button was pressed.";
    }

    if (standardButton==QDialogButtonBox::Open)
    {
        qDebug()<<"The OPEN button was pressed.";
    }
}
