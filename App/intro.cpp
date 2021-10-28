#include "intro.h"

intro::intro(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/Intro.jpg");

    ancho = 800;
    alto = 800;


    timer->start(1);
    connect(timer, &QTimer::timeout, this, &intro::contador);

}

QRectF intro::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void intro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void intro::intro1()
{
    if(columnas <= 8800){
       columnas +=800;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}

void intro::titulo()
{
    if(columnas < 20000){
       columnas +=800;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}

void intro::contador()
{
    cont++;
    if(cont%800 == 0 and columnas <= 8800){
        intro1();
    }
    if(cont%100 == 0 and columnas > 8800){
        titulo();
    }
}


