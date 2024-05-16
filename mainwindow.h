#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "airoplane.h"
#include "bookticket.h"
#include "availabletickets.h"
#include "transactions.h"

#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QPushButton *btnAvailableSeats;
    QPushButton *btnBook;
    QPushButton * btnTransaction;
    airoplane * ptrAiro;
};

#endif // MAINWINDOW_H
