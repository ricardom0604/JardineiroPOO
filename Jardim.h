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
    Jardim();
    ~Jardim();
    void mostra();
};



#endif //JARDIM_H
