//
// Created by bruni on 24/10/2025.
//

#ifndef JARDIM_H
#define JARDIM_H

#include "Settings.h"


class Jardim {
    char mapa[Settings::Jardim::tamanho][Settings::Jardim::tamanho];

public:
    Jardim();
    void inicializa();
    void mostra();
};



#endif //JARDIM_H
