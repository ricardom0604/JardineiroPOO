#ifndef POO_TP_SIMULADOR_H
#define POO_TP_SIMULADOR_H
#include "Comando.h"
#include "Jardim.h"


class Simulador {
    Comando *comando;
    Jardim *jardim;
public:
    Simulador();
    ~Simulador();
    void roda();
};



#endif