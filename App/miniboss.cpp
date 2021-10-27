#include "miniboss.h"

miniboss::miniboss(QObject *parent) : QObject(parent)
{
    timer = new QTimer();

    filas = 0, columnas = 0;

    pixmap = new QPixmap(":/Sprites Personajes/Boss-1.png");

    ancho = 54;
    alto = 54;

    timer->start(1);
    connect(timer, &QTimer::timeout, this, &miniboss::Movimiento);
}

QRectF miniboss::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void miniboss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2, *pixmap, columnas, filas, ancho, alto);
}

void miniboss::Movimiento()
{

    this->update(-ancho/2, -alto/2, ancho, alto);
}
