#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class personaje : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit personaje(int prueba = 0, QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int pos_x = 400, pos_y = 400, vidas = 3, puntos = 0;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void direccion(int direc = 0);


signals:

public slots:
    void Movimiento();

};

#endif // PERSONAJE_H
