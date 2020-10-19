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

private:
    QTimer * myTimer;
};

#endif // CUSTOMTABLEMODEL_H
