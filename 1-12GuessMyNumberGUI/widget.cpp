#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <stdlib.h> // to use srand() and rand() functions
#include <time.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize seeding for random number
    srand(time(NULL));

    //Generate a random number (1-10)
    secretNumber=rand()%10 +1;
    qDebug()<<"Secret Number was generated as "<<QString::number(secretNumber);

    //Disable the start over button
    ui->btnStartOver->setDisabled(true);
    ui->lblMessage->setText("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnGuess_clicked()
{
    guessNumber=ui->spinBox->value();
    qDebug()<<"User selected the guess number: "<<QString::number(guessNumber);

    if (guessNumber==secretNumber)
    {
        ui->lblMessage->setText("Congratulations.You guessed the number.");
        ui->btnGuess->setDisabled(true);
        ui->btnStartOver->setDisabled(false);
    }
    else
    {
        if(guessNumber<secretNumber)
        {
            ui->lblMessage->setText("Number is greater than that.");
        }
        else
        {
            ui->lblMessage->setText("Number is smaller than that.");
        }
    }
}

void Widget::on_btnStartOver_clicked()
{
  //disable the start over button
    ui->btnStartOver->setDisabled(true);

  //enable the guess button
    ui->btnGuess->setDisabled(false);

  //set spin box value to 1
    ui->spinBox->setValue(1);

  //generate a new random number
   secretNumber=rand()%10 +1;
   qDebug()<<"The new secret number generated is "<<QString::number(secretNumber);

}
