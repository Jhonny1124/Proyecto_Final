#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Nivel1 = new QGraphicsScene;
    Nivel2 = new QGraphicsScene;
    astronauta = new personaje();
    level1 = new QGraphicsRectItem();

    level1 = Nivel1->addRect(0,0,80,80, QPen(QColor(1,1,1)), QImage("../TheSpaceBattle/App/Sprites Personajes/Circuito.jpg"));
    Nivel1->addItem(astronauta);
    astronauta->setPos(400,400);
    Nivel1->setBackgroundBrush(QImage("../TheSpaceBattle/App/Sprites Personajes/Galaxia.jpg"));

    ui->graphicsView->setScene(Nivel1);
    ui->graphicsView->setSceneRect(400,400,10,10);
    ui->graphicsView->show();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(conector()));
    timer->start(1);

}

void MainWindow::Level1()
{
    int ran_x, ran_y;
    ran_x = QRandomGenerator::global()->bounded(710);
    ran_y = QRandomGenerator::global()->bounded(710);
    level1->setPos(ran_x,ran_y);
    qDebug() << ran_x << ", " << ran_y << Qt::endl;
}

void MainWindow::conector()
{
    seconds++;
    ui->lcdNumber->display(astronauta->vidas);
    ui->lcdNumber_2->display(astronauta->puntos);
    if(seconds == 3500 or astronauta->collidesWithItem(level1)){
        Level1();
        if(seconds == 3500){
            astronauta->vidas--;
        }
        else{
            astronauta->puntos+=100;
        }
        seconds = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
        switch (e->key()) {
        case Qt::Key_A:
            astronauta->setPos(astronauta->pos_x-=10, astronauta->pos_y);
            if(astronauta->pos_x == 50){
                astronauta->setPos(astronauta->pos_x+=10, astronauta->pos_y);
            }
            astronauta->direccion(1);
            break;
        case Qt::Key_S:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=10);
            if(astronauta->pos_y == 750){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=10);
            }
            break;
        case Qt::Key_D:
            astronauta->setPos(astronauta->pos_x+=10, astronauta->pos_y);
            if(astronauta->pos_x == 750){
                astronauta->setPos(astronauta->pos_x-=10, astronauta->pos_y);
            }
            astronauta->direccion(0);
            break;
        case Qt::Key_W:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=10);
            if(astronauta->pos_y == 50){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=10);
            }
            break;
        default:
            break;
        }
}

