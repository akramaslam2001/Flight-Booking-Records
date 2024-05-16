#ifndef AIROPLANE_H
#define AIROPLANE_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <dbutility.h>

extern int flag;

class airoplane: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    airoplane(QGraphicsItem * parent  = nullptr);
    void book();
    void engigneOnOf(int);
public slots:
    void fly();
private:
    QTimer *timer;
    int engineStatus;
};

#endif // AIROPLANE_H
