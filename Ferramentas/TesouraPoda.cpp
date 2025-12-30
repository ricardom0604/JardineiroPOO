//
// Created by bruni on 23/10/2025.
//

#include "TesouraPoda.h"
#include "Solo.h"
#include <iostream>

void TesouraPoda::usar(Solo& solo, Jardineiro& jardineiro) {
    if (solo.temPlanta()) {
        std::cout << "A tesoura de poda foi utilizada." << std::endl;
    }
}

bool TesouraPoda::estaGasta() const {return false;} //a tesoura nunca se desgata

void TesouraPoda::mostrarInfo() const {Ferramenta::mostrarInfo();}
