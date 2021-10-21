#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Nivel1 = new QGraphicsScene;
    astronauta = new personaje();

    Nivel1->addRect(0,0,20,20,QPen(QColor(0,0,0)),QColor(1,1,1));
    Nivel1->addItem(astronauta);
    astronauta->setPos(0,0);

    ui->graphicsView->setScene(Nivel1);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_A:
        astronauta->setPos(astronauta->pos_x-=5, astronauta->pos_y);
        astronauta->direccion(1);
        break;
    case Qt::Key_S:
        astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=5);
        break;
    case Qt::Key_D:
        astronauta->setPos(astronauta->pos_x+=5, astronauta->pos_y);
        astronauta->direccion(0);
        break;
    case Qt::Key_W:
        astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=5);
        break;
    default:
        break;
    }
}

