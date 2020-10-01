#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Add a button to the user interface and set it central
    QPushButton * myButton=new QPushButton("This button");
    setCentralWidget(myButton);

    //Define a quit action
    QAction * quitAction=new QAction("Quit",this);
    connect(quitAction,&QAction::triggered,[=]()
    {
        QApplication::quit();
    });

    //Add a menubar
    QMenu * fileMenu = menuBar()->addMenu("File"); //mouse over "addMenu" to see the returned type
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    //Add a status bar
    statusBar()->showMessage("Uploading file...",5000); //int timeout in milliseconds e.g. 5000 milliseconds
    //statusBar()->clearMessage();


}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(1000,800);
}

