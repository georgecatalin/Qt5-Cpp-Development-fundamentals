#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* ***  StyleSheets can be set application-wise, this means that all widgets in the application will take that style sheet *** */
    a.setStyleSheet("QPushButton {color:red;background-color:white}");

    Widget w;
    w.show();
    return a.exec();
}
