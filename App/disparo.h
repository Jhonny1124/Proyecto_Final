#ifndef DISPARO_H
#define DISPARO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class disparo : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit disparo(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int posx, posy, cont = 0;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Movimiento();

};

#endif // DISPARO_H
