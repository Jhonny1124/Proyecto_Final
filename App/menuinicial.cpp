#include "menuinicial.h"
#include "ui_menuinicial.h"

MenuInicial::MenuInicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuInicial)
{
    ui->setupUi(this);
    ui->atras->hide();
    ui->contrasena->hide();
    ui->nombre->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->Continuar->hide();
}

MenuInicial::~MenuInicial()
{
    delete ui;
}

void MenuInicial::Escritura(string &texto)
{
   Lectura(texto);

   ofstream archivo;

   archivo.open("../TheSpaceBattle/App/BaseDatos.txt");
   if(!archivo.is_open()){
       cout << "El archivo " << "BaseDatos.txt" << " no pudo ser abierto" << endl;
       exit(1);
   }
   archivo << texto;
   archivo << name+",";
   archivo << pasword+",";
   archivo << "1,";
   if(modo == 0){
       archivo << "1,";
   }
   else{
       archivo << "2,";
   }

   archivo.close();
}

void MenuInicial::Lectura(string &texto)
{
    string add;
    string prueba;
    int coma = 0;

    ifstream archivo;

    archivo.open("../TheSpaceBattle/App/BaseDatos.txt");

    if(!archivo.is_open()){
        cout << "El archivo " << "BaseDatos.txt" << " no pudo ser abierto" << endl;
        exit(1);
    }
    while(getline(archivo, add)){
        texto += add+"\n";
        coma = 0;
        prueba = "";
        if(name != ""){
            for(int i = 0; i < int(add.size()); i++){
                if(add.at(i) != ','){
                    prueba += add.at(i);
                }
                else{
                    coma++;
                    if(coma == 1){
                        if(prueba == name){
                            prueba = "";
                        }
                        else{
                            break;
                        }
                    }
                    if(coma == 2 and equipo == 0){
                        if(prueba == pasword){
                            prueba = "";
                        }
                        else{
                            break;
                        }
                    }
                    if(coma == 3 and equipo == 0){
                        if(prueba == "1"){
                            nivel = 1;
                            prueba = "";
                        }
                        else if(prueba == "2"){
                            nivel = 2;
                            prueba = "";
                        }
                        else if(prueba == "3"){
                            nivel = 3;
                            prueba = "";
                        }
                    }
                    if(coma == 4 and equipo == 0){
                        equipo = 1;
                        if(prueba == "1"){
                            multi = 0;
                        }
                        else if(prueba == "2"){
                            multi = 1;
                        }
                    }
                }
            }
        }
        }
    archivo.close();
}

void MenuInicial::on_Solitario_clicked()
{
    ui->atras->show();
    ui->contrasena->show();
    ui->nombre->show();
    ui->label->show();
    ui->label_2->show();
    ui->Continuar->show();
}

void MenuInicial::on_Continuar_clicked()
{
    name = ui->nombre->text().toStdString();
    pasword = ui->contrasena->text().toStdString();
    string texto;
    if(modo <= 1){
       Escritura(texto);
       equipo = 1;
    }
    else{
        Lectura(texto);
    }
    if(equipo == 1)
        cerrar = 1;
    else{
       // msgBox.setText("Verifique usuario y contraseña");
        //msgBox.exec();
    }
}

void MenuInicial::on_atras_clicked()
{
    ui->atras->hide();
    ui->contrasena->hide();
    ui->nombre->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->Continuar->hide();
    ui->nombre->clear();
    ui->contrasena->clear();
}

void MenuInicial::on_Multijugador_clicked()
{
    ui->atras->show();
    ui->contrasena->show();
    ui->nombre->show();
    ui->label->show();
    ui->label_2->show();
    ui->Continuar->show();
    modo = 1;
}

void MenuInicial::on_CargarPartida_clicked()
{
    ui->atras->show();
    ui->contrasena->show();
    ui->nombre->show();
    ui->label->show();
    ui->label_2->show();
    ui->Continuar->show();
    modo = 2;
}
