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
    explicit personaje(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int pos_x = 0, pos_y = 0;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void direccion(int direc);


signals:

public slots:
    void Movimiento();

};

#endif // PERSONAJE_H
