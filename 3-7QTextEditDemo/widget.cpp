#include "widget.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
   setUI();
}

Widget::~Widget()
{
}

void Widget::setUI()
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


    //Set text and html to the text edit
    QPushButton * plainTextButton =new QPushButton("Plain Text",this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(10,310);
    connect(plainTextButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->setPlainText("Every journey starts with a single step.Johnnie Walker");
    });

    QPushButton * htmlTextButton=new QPushButton("Html Text",this);
    htmlTextButton->setMinimumSize(100,25);
    htmlTextButton->move(110,310);
    connect(htmlTextButton,&QPushButton::clicked,[=]()
    {
        myTextEdit->setHtml("<b>Be</b> patient.");
    });

    //Get text and html from textEdit
    QPushButton * getPlainTextButton=new QPushButton("Get Plain Text",this);
    getPlainTextButton->setMinimumSize(100,25);
    getPlainTextButton->move(10,350);
    connect(getPlainTextButton,&QPushButton::clicked,[=]()
    {
        qDebug()<<"The text from the text edit widget is :"<< myTextEdit->toPlainText();
    });

    QPushButton * getHTMLButton=new QPushButton("Get HTML",this);
    getHTMLButton->setMinimumSize(100,25);
    getHTMLButton->move(110,350);
    connect(getHTMLButton,&QPushButton::clicked,[=]()
    {
        qDebug()<<"The HTML from the text edit widget is :"<<myTextEdit->toHtml();
    });

    setFixedSize(400,400);
}

