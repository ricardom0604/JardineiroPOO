#ifndef COMANDO_H
#define COMANDO_H

#include "Jardim.h"


class Comando {
public:
    Comando(Jardim* &jardim);
    ~Comando();
    std::string obtemInput(std::string message);
    bool executa();
};



#endif //COMANDO_H