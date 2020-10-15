#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileSystemModel>

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
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::Widget *ui;

    QFileSystemModel * dirModel;
    QFileSystemModel * fileModel;
};
#endif // WIDGET_H
