#include "personaje.h"

personaje::personaje(int prueba, QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    if(prueba == 0){
        pixmap = new QPixmap(":/Sprites Personajes/Player1_Mov.png");
    }
    else{
        pixmap = new QPixmap(":/Sprites Personajes/Nave.png");
    }


    ancho = 100;
    alto = 100;

    timer->start(150);
    connect(timer, &QTimer::timeout, this, &personaje::Movimiento);

}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void personaje::direccion(int direc)
{
    if(direc == 0){
        filas = 0;
    }
    else{
        filas = 100;
    }
}

void personaje::Movimiento()
{
    columnas +=100;
    if(columnas >= 300){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
