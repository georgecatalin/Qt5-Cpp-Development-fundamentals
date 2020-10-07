#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Define a QList object
    QList<QString> myList;

    //Add elements in the QList
    /* *** method 1 of adding elements in the list *** */
    myList<<"FirstElement"<<"SecondElement"<<"ThirdElement";


    /* *** method 2 of adding elements in the list *** */
    myList.append("FourthElement");
    myList.append("FifthElement");
    myList.append("SixthElement");

    //Get Data from the QList
    qDebug()<<"The first element in the list is: "<< myList[0];
    qDebug()<<"The second element in the list is: "<<myList[1];
    qDebug()<<"The third element in the list is: "<<myList[2];


    //Count the number of elements in the QList
    qDebug()<<"There are "<<myList.count()<<" elements in the list";

    //Loop through all the elements in the QList
    for(int i=0;i<myList.count();i++)
    {
        qDebug()<<"Element at index "<<QString::number(i)<<"is "<<myList.at(i);
    }

    return a.exec();
}
