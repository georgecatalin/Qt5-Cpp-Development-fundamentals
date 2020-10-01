#ifndef ROCKWIDGET_H
#define ROCKWIDGET_H

#include <QObject>
#include <QWidget>

class RockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RockWidget(QWidget *parent = nullptr);
private slots:
    void buttonClicked();
private:
    QSize sizeHint() const;

signals:

};

#endif // ROCKWIDGET_H
