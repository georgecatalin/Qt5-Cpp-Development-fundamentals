#include "suredialog.h"
#include "ui_suredialog.h"

sureDialog::sureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sureDialog)
{
    ui->setupUi(this);
}

sureDialog::~sureDialog()
{
    delete ui;
}
