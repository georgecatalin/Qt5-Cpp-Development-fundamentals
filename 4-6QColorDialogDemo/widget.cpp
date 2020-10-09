#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //The QPalette class contains color groups for each widget state.
    QPalette palette=ui->label->palette();

    QColor textColor=palette.color(QPalette::WindowText);

    QColor chosenColor=QColorDialog::getColor(textColor,this,"Choose the color for the text");

    if (chosenColor.isValid())
    {
        qDebug()<<"The user has chosen a valid color";

        palette.setColor(QPalette::WindowText,chosenColor);
        ui->label->setPalette(palette);
    }
    else
    {
        qDebug()<<"The user has not chosen a valid color";
    }
}

void Widget::on_pushButton_2_clicked()
{
    QPalette palette=ui->label->palette();

    QColor backgroundColor=palette.color(QPalette::Window);

    QColor selectedColor=QColorDialog::getColor(backgroundColor,this,"Select the new color of the background");

    if (selectedColor.isValid())
    {
        qDebug()<<"User has selected a valid color for the background";

        palette.setColor(QPalette::Window,selectedColor);
        //Reset the palette of the widget to the new palette
        ui->label->setPalette(palette);
    }
    else
    {
        qDebug()<<"User has not selected a valid color for the background";
    }

}

void Widget::on_pushButton_3_clicked()
{

                  bool ok;
                    QFont font = QFontDialog::getFont(
                                    &ok, QFont("Helvetica [Cronyx]", 10), this);
                    if (ok) {
                        // the user clicked OK and font is set to the font the user selected
                        ui->label->setFont(font);
                    } else {
                        // the user canceled the dialog; font is set to the initial
                        // value, in this case Helvetica [Cronyx], 10
                    }


}
