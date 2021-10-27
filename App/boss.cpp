#include "boss.h"

Boss::Boss(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/Boss.png");

    ancho = 300;
    alto = 300;

    timer->start(150);
    connect(timer, &QTimer::timeout, this, &Boss::Movimiento);
}

QRectF Boss::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void Boss::Movimiento()
{
    columnas +=300;
    if(columnas >= 900){
        columnas = 0;
    }
    this->update(-ancho/2, -alto/2, ancho, alto);
}
