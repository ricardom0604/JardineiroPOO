//
// Created by bruni on 23/10/2025.
//

#include "Regador.h"

#include <iostream>

#include "Settings.h"

class Ferramenta;

void Regador::usar(Solo& solo, Jardineiro& jardineiro) {}

bool Regador::estaGasta() const{ return aguaAtual <=0;}

void Regador::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "  Agua restante: " << aguaAtual << "\n";
}
