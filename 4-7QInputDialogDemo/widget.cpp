#include "widget.h"
#include "ui_widget.h"

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

/* *** The QInputDialog class provides a simple convenience dialog to get a single value from the user. *** */

void Widget::on_pushButton_clicked()
{

    /*
    //entering  a double via QInputDialog
    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble() of the number"),
                                       tr("Amount:"), 37.56, -10000, 10000, 2, &ok);
    if (ok)
       qDebug()<<"You entered the number: "<<QString::number(d);
      */

    //entering an element text from a list

    QStringList items;
    items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                         tr("Season:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
        qDebug()<<"You entered this: "<<item;
}
