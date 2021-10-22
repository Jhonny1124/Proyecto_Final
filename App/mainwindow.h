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

    QGraphicsScene *Nivel1;

    personaje *astronauta;
    QGraphicsRectItem *level1;

public slots:
    void Level1();
};
#endif // MAINWINDOW_H
