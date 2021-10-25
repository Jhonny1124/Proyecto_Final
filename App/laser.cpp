#include "laser.h"

Laser::Laser(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/Laser.png");

    ancho = 800;
    alto = 100;

    timer->start(200);
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
    columnas +=100;
    if(columnas >= 800){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
