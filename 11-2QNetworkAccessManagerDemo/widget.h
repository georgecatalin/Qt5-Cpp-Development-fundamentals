#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void readToRead();
    void readFinished();

private:
    Ui::Widget *ui;

    QNetworkAccessManager * networkAccessManager;
    QNetworkReply * networkReply;
    QByteArray * byteArray;
};
#endif // WIDGET_H
