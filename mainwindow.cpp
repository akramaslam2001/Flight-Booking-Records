#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//extern QGraphicsView *view;

void bookTicket();
void availableTickets();
void transactionDetails();

extern MainWindow * ptrMainWindow;;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    setCentralWidget(view);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0, 0, 800, 600);

    btnBook = new QPushButton();
    btnBook->setGeometry(650,10,90,30);
    btnBook->setText("Book Ticket");

    QLabel * ptrlbl = new QLabel();
    ptrlbl->setText("Flight will take only if all tickets are sold");
    ptrlbl->show();
    ptrlbl->move(this->x(), this->y()-20);

    QLabel * ptrlblFooter = new QLabel();
    ptrlblFooter->setText("Project By CppBuzz.com");
    ptrlblFooter->show();
    ptrlblFooter->move(this->x(), this->y()+550);

    //ptrlbl->setStyleSheet()

    btnAvailableSeats = new QPushButton();
    btnAvailableSeats->setGeometry(650,40,90,30);
    btnAvailableSeats->setText("Available Seats");


    btnTransaction = new QPushButton();
    btnTransaction->setGeometry(650,70,90,30);
    btnTransaction->setText("Transaction");

    //menuPtr->show();
    ptrAiro = new airoplane();
    ptrAiro->show();
    scene->addItem(ptrAiro);

    //scene->addItem(btn);
    ptrAiro->setPos(ptrAiro->x()+ 10, ptrAiro->y());

    scene->addWidget(btnBook); //adding button to scene
    scene->addWidget(btnAvailableSeats); //adding button to scene
    scene->addWidget((btnTransaction));
    scene->addWidget(ptrlbl); //adding label to scene
    scene->addWidget(ptrlblFooter); //adding

    QObject::connect(btnBook, &QPushButton::clicked, bookTicket);
    QObject::connect(btnAvailableSeats, &QPushButton::clicked, availableTickets);
    QObject::connect(btnTransaction, &QPushButton::clicked, transactionDetails);
    //QObject::connect(button,&QPushButton::clicked,insert);

}

MainWindow::~MainWindow()
{
    qDebug("in ~MainWindow()");
    delete ui;
    delete ptrMainWindow;

}

void bookTicket()
{
    //frameptr->show(scene());
    qDebug()<<"in bookTicket()";
    bookticket * ptrBookTckt = new bookticket(ptrMainWindow);
    ptrBookTckt->show();
    //ptrBookTckt->setAiroplane(ptrAiro);
    //ptrBookTckt->move(ptrBookTckt->x() + ptrBookTckt->width(), ptrBookTckt->y() + ptrBookTckt->height()/2);
    ptrBookTckt->getTicketsFromDB();
    //todo: delete ptrBookTckt
}



void availableTickets()
{
    qDebug() <<"in available seats()";
    availabletickets * avtktPtr = new availabletickets(ptrMainWindow); //todo: delete this pointer
    avtktPtr->show();
    //avtktPtr->move(avtktPtr->x() + avtktPtr->width(), avtktPtr->y() + avtktPtr->height()/2);
    avtktPtr->getTicketsFromDB();
    //todo: delete avtktPtr
}

void transactionDetails()
{
    qDebug() <<"in available seats()";
    transactions * transPtr = new transactions(ptrMainWindow); //todo: delete this pointer
    transPtr->show();
    //avtktPtr->move(avtktPtr->x() + avtktPtr->width(), avtktPtr->y() + avtktPtr->height()/2);
    transPtr->getTransDataFromDB();
    //todo : delete transPtr
}
