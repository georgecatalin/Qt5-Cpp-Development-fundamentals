#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QColor>
#include <QPushButton>


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
    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();



    void on_saveColorButton_clicked();

    void on_loadColorButton_clicked();

private:
    Ui::Widget *ui;
    QList<QColor> myColorList;

    void saveColor(QString key, QColor color);
    QColor loadColor(QString key);

    void setLoadedColor(QString key,int index, QPushButton * button);

};
#endif // WIDGET_H
