#include "Simulador.h"

#include "Comando.h"


Simulador::Simulador() {
    comando = new Comando();  //criar um novo comando q recebe um jardim
    jardim = nullptr;


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

bool Simulador::criaJardim(int l, int c) {
    delete jardim;
    jardim = new Jardim(l, c);
    return true;
}

bool Simulador::plantar(char tipo,int l, int c) {
    if (!jardim) return false;
    jardim-> planta(l,c,tipo);
    return true;
}