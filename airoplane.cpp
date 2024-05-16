#include "airoplane.h"
#include<QGraphicsScene>
#include <QPushButton>

airoplane::airoplane(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    setPixmap(QPixmap(":/images/airoplane.jpg"));
    setTransformOriginPoint(-100, -100);
    this->setPos(0, 300);
    //Move();
    timer = new QTimer(this);
    //connect(timer->SIGNAL(timeout()), this->SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(fly()));
    timer->start(100);
}

void airoplane::fly()
{
    if(flag == 1)
    {
    qDebug()<<x() << ":"<<y();
    qDebug()<<"its flying";
    setPos(x()+25, y()-20);

    if(pos().y() < -200)
    {
        //scene()->removeItem(this);
        //
        this->setPos(0, 300);
        qDebug() << "airoplance deleted";
        flag= 0;
    }
    }
}

void airoplane::book()
{
    qDebug() << "airoplane::book()";
}

void airoplane::engigneOnOf(int status)
{
    qDebug()<<"airoplane: engineOnOf())";
    this->engineStatus = status;
    //timer->start(100);
}
