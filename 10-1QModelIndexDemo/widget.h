#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QDebug>
#include <QString>

/* *** The QFileSystemModel class provides a data model for the local filesystem. *** */

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    /* *** QFileSystem Class provides a data model for the local file system *** */

    QFileSystemModel * model;

    /* *** typedef QModelIndexList *** */
    /* *** QModelIndex Class is used to locate data in a data model. *** */

    QModelIndex  parentIndex;
};
#endif // WIDGET_H
