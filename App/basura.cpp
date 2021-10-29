#include "basura.h"

basura::basura(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/BasuraEspacial.png");

    ancho = 70;
    alto = 70;

    timer->start(150);
    connect(timer, &QTimer::timeout, this, &basura::Movimiento);
}

QRectF basura::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void basura::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void basura::Movimiento()
{
    columnas +=70;
    if(columnas >= 280){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
