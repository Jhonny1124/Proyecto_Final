#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
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
#include <string>
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
#include "intro.h"
#include "basura.h"
#include "menuinicial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    int curso = 0;
    ~MainWindow();
    void Escritura();
    void Lectura(string &texto);

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    MenuInicial *menu;

    std::string nombre, contrasena;

    std::array< QGraphicsScene *, 3> Niveles;
    std::array< QGraphicsScene *, 4> Escenas;
    QGraphicsScene * jugador[2];
    QGraphicsScene * Final;

    intro *input;
    personaje *astronauta;
    std::array<personaje *, 2> naves;
    basura *BasuraEspacial;
    Laser *laser;
    Boss *boss;
    disparo *shots[2];
    QGraphicsRectItem *level1;
    std::array<QGraphicsEllipseItem *, 55> meteoritos;
    std::array<QGraphicsEllipseItem *, 10> cometas;
    std::array<miniboss *, 7> mini;


    int turno = 0, progreso = 0, continuar = 0, fin = 0;

    int seconds = 0, nivel = 0, indexm = -1, pruebam = 0, cont = 0, nave_index = 0, cambio = 0, reiniciar = 1;

    int indexc = -1, pruebac = 0;
    float t = 0;

    int orbita = 0, index = 0, direccion = 0,  y = 373;

    int cont_disparos = 0, defensa = 0, DuracionLaser = 0, DanoLaser = 0, add = 0;

    float grados[55];
    float grados_boss[7];
    float velocidad[10];

public slots:
    void Level1();
    void MovBasura();
    void Level2(int);
    void MovMeteoritos();
    void MovCometas();
    void MovMiniBoss();
    void MovBoss();
    void MovDisparo();
    void DanoBoss();
    void MovLaser();
    void CambioEscena();
    void limpiarEscena2();
    void limpiarEscena3();
    void GameOver();
    void PasarTurno();
    void GameOverMulti();
    void conector();
};
#endif // MAINWINDOW_H
