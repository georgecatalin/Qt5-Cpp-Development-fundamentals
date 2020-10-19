#include "customtablemodel.h"
#include <QFont>
#include <QBrush>
#include <QTime>

CustomTableModel::CustomTableModel(QObject * parent)
{
   myTimer=new QTimer(this);
   myTimer->setInterval(1000);
   connect(myTimer,&QTimer::timeout,[=]()
   {
       //define the model index of the data that changes with the QTimer object
       QModelIndex topLeft=index(0,0,QModelIndex()); //->Returns the index of the data in row 0 and column 0 with parent.


       emit dataChanged(topLeft,topLeft); //=>This signal is emitted whenever the data in an existing item changes.


   });


   myTimer->start();
}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

 //The View will acknowledge the change through the data() method
QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
   int row=index.row();
   int column=index.column();

   switch (role)
   {
   case Qt::DisplayRole:
       if(row==0 && column==1) return "<--left";
       if(row==1 && column==1) return  "-->right";
       if(row==0 && column==0)
       {
           /* ***
            * [static] QTime QTime::currentTime()
                Returns the current time as reported by the system clock.
           Note that the accuracy depends on the accuracy of the underlying operating system; not all systems provide 1-millisecond accuracy.
           *** */

           return  QTime::currentTime().toString();
       }
       return QString("Row %0, Column %1").arg(row).arg(column);

       break;
   case Qt::FontRole:
       if(row==0 && column==0)
       {
           QFont font;
           font.setBold(true);
           return  font;
       }
       break;
   case Qt::BackgroundRole:
       if(row==1 && column==2)
       {
           QBrush myBrush(Qt::yellow);
           return myBrush;
       }

       break;
   case Qt::TextAlignmentRole:
       if(row==0 && column==1)
       {
           return  Qt::AlignRight;
       }
       break;
   }


    return QVariant();

}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole)
    {
        if(orientation==Qt::Horizontal)
        {
            if(section==0)
            {
                return "First Header";
            }

            if(section==1)
            {
                return "Second Header";
            }

            if (section==2)
            {
                return "Third Header";
            }
        }
    }


    return QVariant();
}

