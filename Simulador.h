#ifndef SIMULADOR_H
#define SIMULADOR_H


class Comando;

class Simulador {
    Comando* comando;
public:
    Simulador();
    ~Simulador();
    void roda();
};



#endif