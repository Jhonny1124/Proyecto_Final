#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QDesktopWidget>
#include <QDebug>
#include <vector>
#include <list>
#include <array>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>
#include <QtMath>
#include "personaje.h"
#include "laser.h"
#include "boss.h"
#include "miniboss.h"
#include "disparo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *Nivel1, *Nivel2, *Nivel3;

    personaje *astronauta, *nave;
    Laser *laser;
    Boss *boss;
    disparo *shot;
    QGraphicsRectItem *level1;
    std::array<QGraphicsEllipseItem *, 55> meteoritos;
    std::array<QGraphicsEllipseItem *, 10> cometas;
    std::array<miniboss *, 7> mini;

    int seconds = 0, nivel = 1, indexm = -1, pruebam = 0, cont = 0;

    int indexc = -1, pruebac = 0;
    float t = 0;

    int orbita = 0, index = 0, direccion = 0;

    int cont_disparos = 0;

    float grados[55];
    float grados_boss[7];
    float velocidad[10];

public slots:
    void Level1();
    void Level2(int);
    void MovMeteoritos();
    void MovCometas();
    void MovMiniBoss();
    void MovBoss();
    void MovDisparo();
    void conector();
};
#endif // MAINWINDOW_H
