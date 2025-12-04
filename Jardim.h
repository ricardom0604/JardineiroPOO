//
// Created by bruni on 24/10/2025.
//

#ifndef JARDIM_H
#define JARDIM_H

#include <sstream>
#include <cstdio>
#include "Settings.h"
#include <string>
#include <iostream>

#include "Ferramentas/Ferramenta.h"
#include "Plantas/Planta.h"

class Solo;

class Jardim {
    int l, c;
    Solo **mapa;


    int numPlantas;
    int numFerramentas;
    Planta **plantas;
    Ferramenta **ferramentas;
public:
    Jardim(int l, int c);
    ~Jardim();
    void mostra();


    void mostraPlantas() const;
    void planta(char l, char c, char tipo);
    void removerPlanta(int l, int c);
    void moverJardineiro(char direcao);

};
#endif