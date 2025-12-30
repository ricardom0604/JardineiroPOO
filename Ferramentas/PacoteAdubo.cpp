//
// Created by bruni on 23/10/2025.
//

#include "PacoteAdubo.h"
#include <iostream>
#include <ostream>

void PacoteAdubo::usar(Solo& solo, Jardineiro& jardineiro) {}

bool PacoteAdubo::estaGasta() const {return quantidade <= 0;}

void PacoteAdubo::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "Quantidade: " << quantidade << std::endl;
}