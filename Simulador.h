#ifndef POO_TP_SIMULADOR_H
#define POO_TP_SIMULADOR_H

#include "Comando.h"


class Simulador {
    Comando* comando;
public:
    Simulador();
    ~Simulador();
    void roda();
};



#endif