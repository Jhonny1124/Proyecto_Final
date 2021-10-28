#include "laser.h"

Laser::Laser(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/Laser.png");

    ancho = 470;
    alto = 125;

    timer->start(150);
    connect(timer, &QTimer::timeout, this, &Laser::Movimiento);
}

QRectF Laser::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void Laser::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void Laser::Movimiento()
{
    if(columnas < 4700){
       columnas +=470;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
