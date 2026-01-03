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
    std::map<std::string, Jardim*> saves;

public:
    Comando();
    ~Comando();

    std::string obtemInput(std::string message);
    bool executa();

    bool processaLinha(std::string linha); //Permite processar uma linha de texto quer venha do cin ou de um ifstream

};

#endif //COMANDO_H