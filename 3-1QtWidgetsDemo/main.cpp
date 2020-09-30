#include <rockwidget.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RockWidget r;
    //r.setWindowTitle("My special Qt Window");
    r.show();

    return a.exec();
}
