//
// Created by bruni on 23/10/2025.
//

#include "FerramentaZ.h"
#include "Solo.h"
#include "Jardineiro.h"
#include <iostream>


void FerramentaZ::usar(Solo& solo, Jardineiro& jardineiro) {
    std::cout << "Usou a Ferramenta Z!" << std::endl;
}

//para saber se a ferramenta deve ser destruída
bool FerramentaZ::estaGasta() const {return false;}// Define se ela desaparece ou é permanente


void FerramentaZ::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "  Propriedades: Especial Z" << std::endl;
}