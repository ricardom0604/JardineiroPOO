//
// Created by bruni on 23/10/2025.
//

#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

#include "Posicao.h"

class Jardim;
using namespace std;

class Solo;

class Planta {

protected: //se meter no private,as classes filhas n podem modificar
    char character;
    float agua, nutrientes;
    string tipoBeleza;;  //feias, bonitas ou neutras
    int contadorInstantes;

public:

    Planta(float agua, int nutrientes, string beleza, char character);

    virtual ~Planta() = default;

    virtual void cadaInstante(Solo& solo) = 0; //simula a passagem de um instante; recebe o solo para poder interagir com ele

    virtual bool verificaMorte(const Solo& solo) const = 0;//verifica se as condições de morte da planta foram atingidas

    virtual void acaoMorte(Solo& solo) = 0; //ação da planta quando morre

    virtual Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) = 0;


    //===GETTERS===
    int getAgua();
    int getNutri();
    string getBeleza();
    char getChar();

    //===SETTERS===
    void setAgua(int a);
    void setNutri(int n);
    void setBeleza(string b);
    void setChar(char c);


    //virtual void cresce();
    virtual void mostrarInfoPlanta() const;

    bool eFeia() const{return tipoBeleza == "feia";}  //tesoura de poda elimina as plantas "feias"
};


#endif //PLANTA_H
