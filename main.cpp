#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <airoplane.h>
#include <QPushButton>
#include <menu.h>
#include "mainwindow.h"

//void bookTicket();
//void availableSeats();

QGraphicsView *view;
MainWindow * ptrMainWindow;
int flag = -1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ptrMainWindow = new MainWindow();
    ptrMainWindow->show();

    return a.exec();
}
