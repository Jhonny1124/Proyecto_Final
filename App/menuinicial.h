#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <string>
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QMessageBox>

using namespace std;

namespace Ui {
class MenuInicial;
}

class MenuInicial : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuInicial(QWidget *parent = nullptr);
    ~MenuInicial();
    void Escritura(string &texto);
    void Lectura(string &texto);
    int cerrar = 0, modo = 0, nivel = 0, equipo = 0, multi = 0;
    string name, pasword;

private slots:
    void on_Solitario_clicked();

    void on_Continuar_clicked();

    void on_atras_clicked();

    void on_Multijugador_clicked();

    void on_CargarPartida_clicked();

    void on_Instrucciones_clicked();

private:
    Ui::MenuInicial *ui;
    QMessageBox msgBox;
    QGraphicsScene * instrucciones;
};

#endif // MENUINICIAL_H
