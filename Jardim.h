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

class Jardim {
    int l, c;
    char **mapa;

public:
    Jardim(int l, int c);
    ~Jardim();
    void mostra();

    void plantar(int l, int c, char tipo);
    void removerPlanta(int l, int c);
    void moverJardineiro(char direcao);

};
#endif