#include "rockwidget.h"
#include <QLabel>


RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("This is Window Title via constructor");
    QLabel * label= new QLabel("My label",this);
}
