#include "TesouraPoda.h"
#include "Solo.h"
#include <iostream>

void TesouraPoda::mostrarInfo() const {Ferramenta::mostrarInfo();}

void TesouraPoda::usar(Solo& solo, Jardineiro&) {
    Planta* p = solo.getPlanta();
    if (!p) return;

    if (p->eFeia()) {
        delete solo.removePlanta();
        std::cout << "Planta feia removida.\n";
    }
}

bool TesouraPoda::estaGasta() const {
    return false; // nunca gasta
}