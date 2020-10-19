#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QVariantMap>  //a map of QVariants

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
    void on_fetchButton_clicked();

    void dataReadyRead();
    void dataFinishedRead();

private:
    Ui::Widget *ui;

    QNetworkAccessManager * networkAccessManager;
    QNetworkReply * networkReply;
    QByteArray * byteArray;
};
#endif // WIDGET_H
