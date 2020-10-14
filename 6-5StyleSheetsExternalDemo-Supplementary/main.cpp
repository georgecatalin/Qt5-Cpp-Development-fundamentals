#include "widget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

// Add this function to read from the text file
QString readTextFile(QString path)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString css=readTextFile(":/new/styles/styles/myStyle.css");

    if (css.length()>0)
    {
        a.setStyleSheet(css);
    }

    Widget w;
    w.show();
    return a.exec();
}
