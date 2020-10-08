#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_okPushButton_clicked()
{
    //Get the data
    QString userPosition=ui->positionLineEdit->text();
    if (!userPosition.isEmpty())
    {
        position=userPosition;
        qDebug()<<"The position is "<<position;

        if (ui->windowsRadioButton->isChecked())
        {
            favouriteOS="Windows";
            qDebug()<<"You selected the Windows Radio Button";
        }

        if(ui->macRadioButton->isChecked())
        {
            favouriteOS="Mac";
            qDebug()<<"You selected the Mac Radio Button";
        }

        if(ui->linuxRadioButton->isChecked())
        {
            favouriteOS="Linux";
            qDebug()<<"You selected the Linux Radio Button";
        }
    }


    //Return result
    accept();

}

void InfoDialog::on_cancelPushButton_clicked()
{
    //Return result
    reject();
}

QString InfoDialog::getFavouriteOS() const
{
    return favouriteOS;
}

QString InfoDialog::getPosition() const
{
    return position;
}
