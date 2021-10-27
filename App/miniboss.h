#ifndef MINIBOSS_H
#define MINIBOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class miniboss : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit miniboss(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Movimiento();

};

#endif // MINIBOSS_H
