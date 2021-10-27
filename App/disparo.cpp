#include "disparo.h"

disparo::disparo(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/disparo.png");

    ancho = 45;
    alto = 25;

    timer->start(150);
    connect(timer, &QTimer::timeout, this, &disparo::Movimiento);
}

QRectF disparo::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void disparo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void disparo::Movimiento()
{
    columnas +=45;
    if(columnas >= 135){
       columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
