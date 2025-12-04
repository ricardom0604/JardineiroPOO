//
// Created by bruni on 23/10/2025.
//

#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

using namespace std;

class Planta {
    char character;
    float agua, nutrientes;
    string tipoBeleza;;  //feias, bonitas ou neutras
public:

    Planta(float agua, int nutrientes, string beleza, char character);

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


    virtual void cresce();
    virtual void mostrarInfoPlanta() const;
};



#endif //PLANTA_H
