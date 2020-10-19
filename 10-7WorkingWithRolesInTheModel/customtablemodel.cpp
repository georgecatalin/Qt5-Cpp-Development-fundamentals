#include "customtablemodel.h"
#include <QFont>
#include <QBrush>

CustomTableModel::CustomTableModel(QObject * parent)
{

}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
   int row=index.row();
   int column=index.column();

   switch (role)
   {
   case Qt::DisplayRole:
       if(row==0 && column==1) return "<--left";
       if(row==1 && column==1) return  "-->right";
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
