#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QItemSelection>
#include <QDebug>

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
    void selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::Widget *ui;

    QStandardItemModel * model;
};
#endif // WIDGET_H
