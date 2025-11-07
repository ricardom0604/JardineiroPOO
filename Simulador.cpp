#include "Simulador.h"

Simulador::Simulador() {
    comando = new Comando();  //criar um novo comando q recebe um jardim
}

Simulador::~Simulador() {
    delete comando;
}

void Simulador::roda() {
    while (true) {
        if (!comando->executa())
            break;
    }
}