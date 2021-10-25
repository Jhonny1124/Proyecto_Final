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
    nave = new personaje(1);
    level1 = new QGraphicsRectItem();
    laser = new Laser();

    //Nivel 1 //
////////////////////////////////////////////////////////////////////////////////////////////////////
    /*level1 = Nivel1->addRect(0,0,80,80, QPen(QColor(1,1,1)), QImage("../TheSpaceBattle/App/Sprites Personajes/Circuito.jpg"));
    Nivel1->addItem(astronauta);
    astronauta->setPos(400,400);
    Nivel1->setBackgroundBrush(QImage("../TheSpaceBattle/App/Sprites Personajes/Galaxia.jpg"));

    ui->graphicsView->setScene(Nivel1);
    ui->graphicsView->setSceneRect(400,400,10,10);
    ui->graphicsView->show();*/

////////////////////////////////////////////////////////////////////////////////////////////////////

    nivel = 2;
    Nivel2->addItem(nave);
    Nivel2->setBackgroundBrush(QImage("../TheSpaceBattle/App/Sprites Personajes/Galaxia.jpg"));
    nave->setPos(55,400);
    nave->pos_x = 55;
    nave->pos_y = 400;

    for(int g = 0; g < 55; g++){
        grados[g] = 0;
    }
    for(int v = 0; v < 10; v++){
        velocidad[v] = 85*qSin(qDegreesToRadians(30.0));
    }

    ui->graphicsView->setScene(Nivel2);

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
}

void MainWindow::Level2(int a = 0)
{
    if(a == 0){
        indexm++;

        meteoritos.at(indexm) = Nivel2->addEllipse(720,QRandomGenerator::global()->bounded(710),90,90, QPen(QColor(1,1,1)), QImage("../TheSpaceBattle/App/Sprites Personajes/Meteorito.jpg"));

        pruebam++;
    }
    else{
        indexc++;

        cometas.at(indexc) = Nivel2->addEllipse(720,nave->pos_y,45,45, QPen(QColor(1,1,1)), QImage("../TheSpaceBattle/App/Sprites Personajes/Cometas.jpg"));

        pruebac++;
    }

}

void MainWindow::MovMeteoritos()
{

    for(int i = 0; i < pruebam; i++){
        if(meteoritos.at(i) != NULL){
            meteoritos.at(i)->setPos(meteoritos.at(i)->pos().x()-0.3,70*qSin(qDegreesToRadians(grados[i]))-(meteoritos.at(i)->pos().y()));
            grados[i]++;
            if(meteoritos.at(i)->pos().x() < -810){
                Nivel2->removeItem(meteoritos.at(i));
                meteoritos.at(i) = NULL;
            }
            if(nave->collidesWithItem(meteoritos.at(i))){
                Nivel2->removeItem(meteoritos.at(i));
                meteoritos.at(i) = NULL;
                nave->vidas--;
            }
        }
    }
}

void MainWindow::MovCometas()
{
    static float t = 0.01, Vx = 100*qCos(qDegreesToRadians(30.0)), g = 9.81;
    for(int i = 0; i < pruebac; i++){
        if(cometas.at(i) != NULL){
            cometas.at(i)->setPos(cometas.at(i)->pos().x()-(Vx*t), cometas.at(i)->pos().y()-(velocidad[i])*t+((g/2)*(t*t)));
            velocidad[i] = velocidad[i] - g*t;
            if(cometas.at(i)->pos().x() < -765){
                Nivel2->removeItem(cometas.at(i));
                cometas.at(i) = NULL;
            }
            if(nave->collidesWithItem(cometas.at(i))){
                Nivel2->removeItem(cometas.at(i));
                cometas.at(i) = NULL;
                nave->vidas--;
            }
        }
    }
}


void MainWindow::conector()
{
    seconds++;
    if(nivel == 1){
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
    else if(nivel == 2){
        ui->lcdNumber->display(nave->vidas);
        ui->lcdNumber_2->display(nave->puntos);
        if(pruebam > 0 and seconds%2 == 0)
            MovMeteoritos();
        if(pruebac > 0 and seconds%3 == 0)
            MovCometas();
        if(seconds%1000 == 0 and indexm < 54){
            Level2();
            if(seconds == 6000 and indexc < 9){
                Level2(1);
                seconds = 0;
            }
        }
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
            nave->setPos(nave->pos_x, nave->pos_y+=10);
            if(nave->pos_y == 750){
                nave->setPos(nave->pos_x, nave->pos_y-=10);
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
            nave->setPos(nave->pos_x, nave->pos_y-=10);
            if(nave->pos_y == 50){
                nave->setPos(nave->pos_x, nave->pos_y+=10);
            }
            break;
        default:
            break;
        }
}

