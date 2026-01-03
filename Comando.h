#ifndef COMANDO_H
#define COMANDO_H

#include "Jardim.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "Simulador.h"

class Comando {
    Jardim *jardim = nullptr;
    bool jardimCriado = false;
    void mostraAjuda() const;
public:
    Comando();
    ~Comando();

    std::string obtemInput(std::string message);
    bool executa();
};

#endif //COMANDO_H