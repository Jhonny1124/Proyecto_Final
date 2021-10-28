#ifndef INTRO_H
#define INTRO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class intro : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit intro(QObject *parent = nullptr);

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;

    float ancho, alto;

    int cont;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void intro1();
    void titulo();
    void contador();
};

#endif // INTRO_H
