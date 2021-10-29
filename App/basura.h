#ifndef BASURA_H
#define BASURA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class basura : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit basura(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int posx, posy;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Movimiento();

};

#endif // BASURA_H
