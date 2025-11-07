#ifndef COMANDO_H
#define COMANDO_H

#include "Jardim.h"
#include <sstream>
#include <iostream>

#include "Simulador.h"

class Comando {
    Jardim *jardim;
public:
    Comando();
    ~Comando();
    std::string obtemInput(std::string message);
    bool executa();
    bool temInt(std::istringstream &iss,int &i);
    bool temChar(std::istringstream &iss, char &c);
};



#endif //COMANDO_H