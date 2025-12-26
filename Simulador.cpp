#include "Simulador.h"
#include "Comando.h"

Simulador::Simulador() {
    comando = new Comando();
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
