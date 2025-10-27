//
// Created by bruni on 24/10/2025.
//

#ifndef JARDIM_H
#define JARDIM_H

#include "Settings.h"


class Jardim {
    int l, c;
    char **mapa;

public:
    Jardim(int l, int c);
    ~Jardim();
    void mostra();
};



#endif //JARDIM_H
