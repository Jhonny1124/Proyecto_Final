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

    QGraphicsScene *Nivel1, *Nivel2;

    personaje *astronauta, *nave;
    QGraphicsRectItem *level1;
    std::array<QGraphicsEllipseItem *, 55> meteoritos;

    int seconds = 0, nivel = 1, index = -1, prueba = 0;

    float grados[55];

public slots:
    void Level1();
    void Level2();
    void MovMeteoritos();
    void conector();
};
#endif // MAINWINDOW_H
