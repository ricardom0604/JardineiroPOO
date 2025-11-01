#include "Simulador.h"

Simulador::Simulador() {
    comando = new Comando(jardim);
    jardim->mostra();
}

Simulador::~Simulador() {
    delete comando;
    delete jardim;
}

void Simulador::roda() {
    while (true) {
        if (!comando->executa())
            break;
    }
}