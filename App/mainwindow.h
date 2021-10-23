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

    int seconds = 0, nivel = 1;

public slots:
    void Level1();
    void conector();
};
#endif // MAINWINDOW_H
