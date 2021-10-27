#ifndef BOSS_H
#define BOSS_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Boss : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Boss(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int vidas = 3;


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Movimiento();

};

#endif // BOSS_H
