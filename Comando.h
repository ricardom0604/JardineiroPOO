//
// Created by bruni on 27/10/2025.
//

#ifndef COMANDO_H
#define COMANDO_H

#include "Jardim.h"


class Comando {
public:
    Comando();
    ~Comando();
    std::string obtemInput(std::string message);
    bool executa();
};



#endif //COMANDO_H
