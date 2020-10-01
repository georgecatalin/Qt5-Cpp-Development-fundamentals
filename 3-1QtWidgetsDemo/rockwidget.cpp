#include "rockwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>


RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("This is Window Title via constructor");
    QLabel * label= new QLabel("My label",this);

    //Add a styled Widget and move it around

    QFont labelStyledFont("Times", 20, QFont::Bold);

    QPalette labelStyledPalette;
    labelStyledPalette.setColor(QPalette::WindowText,Qt::blue);
    labelStyledPalette.setColor(QPalette::Window,Qt::red);



    QLabel * labelStyled=new QLabel(this);
    labelStyled->setText("This is the styled label");
    labelStyled->move(50,50); // 0,0 is the upper left corner of the screen. +x means towards the right, +y means towards the buttom

    labelStyled->setFont(labelStyledFont); // adding the defined font to the style of the QLabel widget
    labelStyled->setAutoFillBackground(true); // this is necessary to apply the new color of the background
    labelStyled->setPalette(labelStyledPalette);


    //Add another label and style it by changing the color, font size and font family
    QLabel * newStyledLabel=new QLabel(this);
    newStyledLabel->setText("This is the second label");
    newStyledLabel->move(80,200);

    QFont newStyleLabelFont("Times", 10, QFont::Bold);
    newStyledLabel->setFont(newStyleLabelFont);

    QPalette newStyledPalette;
    newStyledPalette.setColor(QPalette::Window,Qt::green);
    newStyledPalette.setColor(QPalette::WindowText,Qt::black);

    newStyledLabel->setAutoFillBackground(true);
    newStyledLabel->setPalette(newStyledPalette);


    //Add a button and connect a slot
    QPushButton * myButton=new QPushButton(this);
    myButton->setText("Click me!");
    myButton->move(400,150);

    QFont fontButton("Times",50,QFont::Bold);
    myButton->setFont(fontButton);


    //connect the signal emitted by the click of the button to the slot method
   connect(myButton,SIGNAL(clicked()),this,SLOT(buttonClicked()));


}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this,"New event announced","The user has clicked a button.");
}

QSize RockWidget::sizeHint() const
{
    return QSize(1000,1000);
}
