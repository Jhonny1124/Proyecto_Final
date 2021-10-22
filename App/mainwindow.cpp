#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Nivel1 = new QGraphicsScene;
    astronauta = new personaje();
    level1 = new QGraphicsRectItem();

    Nivel1->addItem(astronauta);
        level1 = Nivel1->addRect(10,10,40,40, QPen(QColor(1,1,1)));
    astronauta->setPos(0,0);

    ui->graphicsView->setScene(Nivel1);
    ui->graphicsView->setSceneRect(0,0,10,10);
    ui->graphicsView->show();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Level1()));
    timer->start(1000);

}

void MainWindow::Level1()
{
    level1->setPos(QRandomGenerator::global()->bounded(-355,355),QRandomGenerator::global()->bounded(-355,355));
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
            if(astronauta->pos_x == -345){
                astronauta->setPos(astronauta->pos_x+=5, astronauta->pos_y);
            }
            astronauta->direccion(1);
            break;
        case Qt::Key_S:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=5);
            if(astronauta->pos_y == 345){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=5);
            }
            break;
        case Qt::Key_D:
            astronauta->setPos(astronauta->pos_x+=5, astronauta->pos_y);
            if(astronauta->pos_x == 345){
                astronauta->setPos(astronauta->pos_x-=5, astronauta->pos_y);
            }
            astronauta->direccion(0);
            break;
        case Qt::Key_W:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=5);
            if(astronauta->pos_y == -345){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=5);
            }
            break;
        default:
            break;
        }
}

