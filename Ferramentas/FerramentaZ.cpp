#include "FerramentaZ.h"
#include "Solo.h"
#include <iostream>

FerramentaZ::FerramentaZ()
    : Ferramenta("Ferramenta Z (Drenador)", 'z') {}

void FerramentaZ::usar(Solo& solo, Jardineiro&) {
    int retirar = solo.getAgua() / 2;
    solo.retiraAgua(retirar);
}

bool FerramentaZ::estaGasta() const {
    return false; // por agora nunca gasta
}

void FerramentaZ::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "Tipo: Drenador (remove metade da agua do solo)\n";
}
