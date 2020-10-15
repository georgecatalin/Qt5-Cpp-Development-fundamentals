#include "widget.h"

#include <QApplication>



/* *** The QDir class provides access to directory structures and their contents *** */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
