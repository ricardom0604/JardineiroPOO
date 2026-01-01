#include "FerramentaZ.h"
#include "Solo.h"
#include <iostream>

static const int Z_USOS = 3; // podes ajustar

FerramentaZ::FerramentaZ() : Ferramenta("Ferramenta Z (Drenador)", 'z') {}

void FerramentaZ::usar(Solo& solo, Jardineiro& /*jardineiro*/) {
    int aguaAtual = solo.getAgua();
    solo.retiraAgua(aguaAtual);
    std::cout << "[DrenadorZ] Removeu " << aguaAtual << " de agua do solo.\n";
}

bool FerramentaZ::estaGasta() const {
    // para já não está a gastar (se quiseres “gastar”, diz-me e eu adiciono contador)
    return false;
}

void FerramentaZ::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "Tipo: Drenador (remove toda a agua do solo)\n";
}
