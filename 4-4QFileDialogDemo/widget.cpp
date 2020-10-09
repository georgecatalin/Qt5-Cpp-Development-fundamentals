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


void Widget::on_pushButton_clicked()
{
    /*
    //getExistingDirectory : a convenience static function that will return an existing directory selected by the user.
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);

    qDebug()<<"The directory selected is: "<<dir;
    */

    /*
    //getOpenFileName : a convenience static function that returns an existing file selected by the user. If the user presses Cancel, it returns a null string.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));

    qDebug()<<"The file opened is : "<<fileName;
    */

    /*
    //getOpenFileNames :  a convenience static function that will return one or more existing files selected by the user.
    QStringList files = QFileDialog::getOpenFileNames(
                            this,
                            "Select one or more files to open",
                            "/home",
                            "Images (*.png *.xpm *.jpg)");

    qDebug()<<"The selected files are: "<<files;
    */

    //getSaveFileName : a convenience static function that will return a file name selected by the user. The file does not have to exist.
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/jana/untitled.png",
                               tr("Images (*.png *.xpm *.jpg)"));

    qDebug()<<"The saved file is : "<<fileName;
}
