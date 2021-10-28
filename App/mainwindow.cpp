#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Nivel1 = new QGraphicsScene;
    Nivel2 = new QGraphicsScene;
    Nivel3 = new QGraphicsScene;
    astronauta = new personaje();
    nave = new personaje(1);
    level1 = new QGraphicsRectItem();
    laser = new Laser();
    shot = new disparo();
    boss = new Boss();

    //Nivel 1 //
////////////////////////////////////////////////////////////////////////////////////////////////////
    /*level1 = Nivel1->addRect(0,0,80,80, QPen(QColor(1,1,1)), QImage("../TheSpaceBattle/App/Sprites Personajes/Circuito.jpg"));
    Nivel1->addItem(astronauta);
    astronauta->setPos(400,400);
    Nivel1->setBackgroundBrush(QImage("../TheSpaceBattle/App/Sprites Personajes/Galaxia.jpg"));

    ui->graphicsView->setScene(Nivel1);*/


////////////////////////////////////////////////////////////////////////////////////////////////////

    //Nivel 2//

////////////////////////////////////////////////////////////////////////////////////////////////////

    /*nivel = 2;
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

    ui->graphicsView->setScene(Nivel2);*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

    Nivel3->addItem(boss);
    Nivel3->addItem(nave);
    Nivel3->addItem(shot);
    Nivel3->addItem(laser);
    laser->setPos(0,-150);
    shot->setPos(-30,-30);
    Nivel3->setBackgroundBrush(QImage("../TheSpaceBattle/App/Sprites Personajes/Galaxia.jpg"));
    nivel = 3;
    nave->setPos(55,400);
    nave->pos_x = 55;
    nave->pos_y = 400;
    boss->setPos(650,400);

    for(int g = 0; g < 7; g++){
        grados_boss[g] = 0;
    }

    ui->graphicsView->setScene(Nivel3);

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

void MainWindow::MovMiniBoss()
{
    for(int i = 0; i < orbita; i++){
        mini.at(i)->setPos( -200*qCos(qDegreesToRadians(grados_boss[i]))+623, 200*qSin(qDegreesToRadians(grados_boss[i]))+373);
        grados_boss[i]++;
    }

}

void MainWindow::MovBoss()
{
    static int y = 373;

    if(y == 653){
        direccion = 1;
    }
    if(y == 163){
        direccion = 0;
    }
    if(direccion == 0){
        y+=10;
    }
    else{
        y-=10;
    }
    for(int i = 0; i < orbita; i++){
        if(mini.at(i) != NULL){
            mini.at(i)->setPos( -200*qCos(qDegreesToRadians(grados_boss[i]))+623, 200*qSin(qDegreesToRadians(grados_boss[i]))+y);
            grados_boss[i]++;
        }
    }
    boss->setPos(boss->pos().x(),y);
}

void MainWindow::MovDisparo()
{
        shot->posx+=10;
        shot->setPos(shot->posx, shot->posy);

}

void MainWindow::DanoBoss()
{
    if(shot->posx == 755){
        shot->setPos(-30,-30);
        shot->posx = -30;
        cont_disparos = 0;
    }
    if(orbita == 7){
        for(int i = 0; i < orbita; i++){
            if(mini.at(i) != NULL){
                if(shot->collidesWithItem(mini.at(i))){
                    shot->setPos(-30,-30);
                    shot->posx = -30;
                    Nivel3->removeItem(mini.at(i));
                    mini.at(i) = NULL;
                    cont_disparos = 0;
                }
            }
        }
    }
    if(defensa < 7){
        if(mini.at(defensa) == NULL){
            defensa++;
        }
    }
    if(shot->collidesWithItem(boss)){
        shot->setPos(-30,-30);
        shot->posx = -30;
        cont_disparos = 0;
        if(defensa == 7){
            boss->vidas--;
        }
    }
}

void MainWindow::MovLaser()
{
    laser->setPos(boss->pos().x()-410, boss->pos().y());
    if(DuracionLaser == 4000){
        laser->columnas = 0;
    }
    if(DuracionLaser == 6000){
        DuracionLaser = 0;
        DanoLaser = 0;
        laser->setPos(0, -150);
    }


}


void MainWindow::conector()
{
    seconds++;
    if(nivel == 1){
        ui->lcdNumber->display(astronauta->vidas);
        ui->lcdNumber_2->display(astronauta->puntos);
        if(seconds%3500 == 0 or astronauta->collidesWithItem(level1)){
            Level1();
            if(seconds%3500 == 0){
                astronauta->vidas--;
            }
            else{
                astronauta->puntos+=100;
            }
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
            if(seconds%6000 == 0 and indexc < 9){
                Level2(1);
            }
        }
    }
    else if(nivel == 3){
        ui->lcdNumber->display(nave->vidas);
        ui->lcdNumber_2->display(nave->puntos);
        if(cont_disparos > 0 and shot->posx != -30){
            DanoBoss();
            if(seconds%30 == 0)
                MovDisparo();
        }
        if(orbita < 7){
            if(seconds%500 == 0){
                mini.at(index) = new miniboss();
                mini.at(index)->setPos(650,400);
                Nivel3->addItem(mini.at(index));
                index++;
                orbita++;
            }
            if(orbita > 0 and seconds%10 == 0){
                MovMiniBoss();
            }
        }
        else{
            DuracionLaser++;
            if(DuracionLaser >= 4000){
                MovLaser();
                if(nave->collidesWithItem(laser) and DanoLaser == 0){
                    nave->vidas--;
                    DanoLaser = 1;
                }
            }
            if(orbita > 0 and seconds%70 == 0){
                MovBoss();
            }
            if(nave->collidesWithItem(boss)){
                nave->vidas--;
                nave->setPos(55,400);
                nave->pos_x = 55;
                nave->pos_y = 400;
            }
            for(int i = 0; i < orbita; i++){
                if(mini.at(i) != NULL){
                    if(nave->collidesWithItem(mini.at(i))){
                        nave->vidas--;
                        nave->setPos(55,400);
                        nave->pos_x = 55;
                        nave->pos_y = 400;
                    }
                }
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
            if(astronauta->pos_x <= 50){
                astronauta->setPos(astronauta->pos_x+=10, astronauta->pos_y);
            }
            astronauta->direccion(1);
            nave->setPos(nave->pos_x-=10, nave->pos_y);
            if(nave->pos_x <= 50){
                nave->setPos(nave->pos_x+=10, nave->pos_y);
            }
            break;
        case Qt::Key_S:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=10);
            if(astronauta->pos_y >= 750){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=10);
            }
            nave->setPos(nave->pos_x, nave->pos_y+=10);
            if(nave->pos_y >= 750){
                nave->setPos(nave->pos_x, nave->pos_y-=10);
            }
            break;
        case Qt::Key_D:
            astronauta->setPos(astronauta->pos_x+=10, astronauta->pos_y);
            if(astronauta->pos_x >= 750){
                astronauta->setPos(astronauta->pos_x-=10, astronauta->pos_y);
            }
            nave->setPos(nave->pos_x+=10, nave->pos_y);
            if(nave->pos_x >= 750){
                nave->setPos(nave->pos_x-=10, nave->pos_y);
            }
            astronauta->direccion(0);
            break;
        case Qt::Key_W:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=10);
            if(astronauta->pos_y <= 50){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=10);
            }
            nave->setPos(nave->pos_x, nave->pos_y-=10);
            if(nave->pos_y <= 50){
                nave->setPos(nave->pos_x, nave->pos_y+=10);
            }
            break;
        case Qt::Key_Space:
            if(nivel == 3){
                cont_disparos++;
                if(cont_disparos == 1){
                    shot->posx = nave->pos_x+70;
                    shot->posy = nave->pos_y;
                    shot->setPos(shot->posx,shot->posy);
                }
            }
            break;
        default:
            break;
        }
}

