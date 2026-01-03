#include "PacoteAdubo.h"
#include <iostream>
#include <ostream>

#include "Solo.h"

bool PacoteAdubo::estaGasta() const {return quantidade <= 0;}

void PacoteAdubo::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "Quantidade: " << quantidade << std::endl;
}
void PacoteAdubo::usar(Solo& solo, Jardineiro&) {
    if (quantidade <= 0) return;

    solo.adicionaNutrientes(Settings::Adubo::dose);
    quantidade -= Settings::Adubo::dose;

    if (quantidade < 0) quantidade = 0;
}