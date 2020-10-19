#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QTimer>

class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTableModel(QObject * parent);

    //override some methods to provide functionality
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;


   QVariant data(const QModelIndex &index,int role) const; // controls the data that is shown in each cell

   /* ***
    * [virtual] QVariant QAbstractItemModel::headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const
       Returns the data for the given role and section in the header with the specified orientation.
      For horizontal headers, the section number corresponds to the column number. Similarly, for vertical headers, the section number corresponds to the row number.
    * *** */

   QVariant headerData(int section, Qt::Orientation orientation, int role) const;



private:
    QTimer * myTimer;
};

#endif // CUSTOMTABLEMODEL_H
