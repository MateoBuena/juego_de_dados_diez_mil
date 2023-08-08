#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

/*LIBRERIA CASERA PARA CREACION DE DADOS Y SUS FUNCIONES
 COMO LA DE DAR VALORES RANDOMS ENTRE 1 Y 6*/

 //CREACION DE LOS CUADRADOS PARA LOS DADOS

 void dibujarCuadrado(int posx, int posy){
    for(int x=0;x<7;x++){
        for(int y=0;y<3;y++){
            rlutil::locate(x+posx,y+posy);
            rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
            std::cout<<" ";

        }
    }


    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
 }
//FIN CREACION DE LOS CUADRADOS PARA LOS DADOS.

//LADOS DE LOS PUNTOS:

void centro(int posx, int posy){

    rlutil::locate(posx+3,posy+1);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)254;
}

void arribaizq(int posx, int posy){
    rlutil::locate(posx+1,posy);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)220;
}

void arribader(int posx, int posy){

    rlutil::locate(posx+5,posy);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)220;
}

void arribacentro(int posx, int posy){
    rlutil::locate(posx+3,posy);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)220;
}

void abajoizq(int posx, int posy){

    rlutil::locate(posx+1,posy+2);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)223;
}

void abajoder(int posx, int posy){
    rlutil::locate(posx+5,posy+2);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)223;
}

void abajocentro(int posx, int posy){
    rlutil::locate(posx+3,posy+2);
    rlutil::setBackgroundColor(rlutil::COLOR::WHITE);
    rlutil::setColor(rlutil::COLOR::BLACK);
    std::cout<<(char)223;
}

//FIN LADOS DE LOS DADOS.

//DIBUJO DE LOS DADOS:

void dibujardado(int posx, int posy, int num ){
    dibujarCuadrado(posx,posy);
    switch(num){
case 1:
    centro(posx,posy);
    break;
case 2:
    arribader(posx,posy);
    abajoizq(posx,posy);
    break;
case 3:
    arribader(posx,posy);
    centro(posx,posy);
    abajoizq(posx,posy);
    break;
case 4:
    arribaizq(posx,posy);
    arribader(posx,posy);
    abajoizq(posx,posy);
    abajoder(posx,posy);
    break;
case 5:
    arribaizq(posx,posy);
    arribader(posx,posy);
    centro(posx,posy);
    abajoizq(posx,posy);
    abajoder(posx,posy);
    break;
case 6:
    arribaizq(posx,posy);
    arribacentro(posx,posy);
    arribader(posx,posy);
    abajoizq(posx,posy);
    abajocentro(posx,posy);
    abajoder(posx,posy);
    break;
default:
    break;
    }

}

//FIN CREADOR DE DADOS.
