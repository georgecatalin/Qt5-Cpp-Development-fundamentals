#include "widget.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont labelFont("Times",10,QFont::Bold);
    QLabel * thisLabel=new QLabel("This is my text",this);
    thisLabel->setFont(labelFont);
    thisLabel->move(100,25);

    QTextEdit * myTextEdit=new QTextEdit(this);
    myTextEdit->move(70,55);

    /*

    //Signal textChanged()
    connect(myTextEdit,&QTextEdit::textChanged,[=]()
    {
        qDebug()<<"Text Changed";
    });

    */

    /* operations to play with here:
     * Copy
     * Paste
     * Undo
     * Redo
     * setHTML
     * setPlainText
     */

    QPushButton * copyButton=new QPushButton("Copy", this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->copy();
    });

    QPushButton * cutButton =new QPushButton("Cut", this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->cut();
    });

    QPushButton * pasteButton =new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->paste();
    });


    //Undo and Redo actions with the textEdit
    QPushButton * undoButton=new QPushButton("Undo",this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(10,280);
    connect(undoButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->undo();
    });


    QPushButton * redoButton =new QPushButton("Redo",this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(110,280);
    connect(redoButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->redo();
    });

}

Widget::~Widget()
{
}

