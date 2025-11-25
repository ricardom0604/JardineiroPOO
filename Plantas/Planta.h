//
// Created by bruni on 23/10/2025.
//

#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>

class Planta {

    int agua, nutrientes;
public:


    Planta(agua, nutrientes);
    int getAgua();
    int getNutri();
    int getBelz();


    //void mostrarInfoPlanta() const;
    virtual void beleza();
    virtual void cresce();
    virtual void mostrarInfoPlanta() const;
};



#endif //PLANTA_H
