#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <map>
#include <string>
#include "Jardim.h"

//comentario para teste
class Comando;

class Simulador {
    Jardim* jardim;
    Comando* comando;
    std::map<std::string, Jardim*> saves; //onde guardamos as cópias
public:
    Simulador();
    ~Simulador();

    //====GETTERS====
    Jardim* getJardim() { return jardim; }

    //====SETTERS====
    void setJardim(Jardim* novo) { jardim = novo; }
    std::map<std::string, Jardim*>& getSaves() { return saves; }

    void roda();
};

#endif
