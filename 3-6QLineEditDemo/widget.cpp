#include "widget.h"
#include <QtDebug>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //First Name
    QLabel * firstNameLabel=new QLabel("First Name",this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10,10);

    QLineEdit * firstNameLineEdit=new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);


    //Last Name
    QLabel * lastNameLabel=new QLabel("Last Name",this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10,70);

    QLineEdit * lastNameLineEdit=new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100,70);

    //City
    QLabel * cityLabel=new QLabel("City",this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->move(10,130);

    QLineEdit * cityLineEdit=new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->move(100,130);

    //Push Button
    QFont myFont("Times",20,QFont::Bold);
    QPushButton * myButton=new QPushButton("Grab Data",this);
    myButton->setFont(myFont);
    myButton->move(80,190);

    connect(myButton,&QPushButton::clicked,[=]()
    {
        QString firstName=firstNameLineEdit->text();
        QString lastName=lastNameLineEdit->text();
        QString city=cityLineEdit->text();

        //Input Data sanitization: make sure there are no empty fields

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug()<<"First Name: "<<firstName;
            qDebug()<<"Last Name: "<<lastName;
            qDebug()<<"City: "<<city;

        }
        else
        {
            qDebug()<<"One field is empty.";
        }
    });

    //Respond to signals for QLineEdit

    /*
    // Signal cursorPositionChanged
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=]()
    {
        qDebug()<<"The current cursor is at position: "<<firstNameLineEdit->cursorPosition();
    });
    */

    /*
    //Signal editingFinished() : happens when user clicks "Enter" or the widget loses focus

    connect(firstNameLineEdit,&QLineEdit::editingFinished,[=]()
    {
        qDebug()<<"Editing is finished";
    });
    */

    /*
    //Signal returnPressed() :  is emitted when the Return or Enter key is pressed
    connect(firstNameLineEdit,&QLineEdit::returnPressed,[=]()
    {
        qDebug()<<"Return pressed";
    });
    */

    /*
    //Signal selectionChanged() : This signal is emitted whenever the selection changes.
    connect(firstNameLineEdit,&QLineEdit::selectionChanged,[=]()
    {
        qDebug()<<"Selection has changed";
    });
    */

    /*
    //Signal textChanged(const QString &text) :  is emitted whenever the text changes. The text argument is the new text.
    connect(firstNameLineEdit,&QLineEdit::textChanged,[=]()
    {
       qDebug()<<"Text has changed: "<<firstNameLineEdit->text();
    });
    */


    //Signal textEdited(const QString &text) : is emitted whenever the text is edited. The text argument is the new text.
    //Unlike textChanged(), this signal is not emitted when the text is changed programmatically, for example, by calling setText().
    connect(firstNameLineEdit,&QLineEdit::textEdited,[=]()
    {
        qDebug()<<"Text has been edited and this is not triggered when doing it programmatically. "<<firstNameLineEdit->text();
    });





    //Set the text of QLineEdit programmatically
    firstNameLineEdit->setText("George Calin");

    //Set hints for the expected text programmatically
    firstNameLineEdit->setPlaceholderText("First Name");
    lastNameLineEdit->setPlaceholderText("Last Name");
    cityLineEdit->setPlaceholderText("City");
}

Widget::~Widget()
{
}

