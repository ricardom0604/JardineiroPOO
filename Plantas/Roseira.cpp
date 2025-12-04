//
// Created by bruni on 23/10/2025.
//

#include "Roseira.h"
#include "iostream"

Roseira::Roseira() :Planta(Settings::Roseira::inicial_agua,Settings::Roseira::inicial_nutrientes, "bonita" ,'r') {
    std::cout << "A construir Roseira \n" << std::endl;
}

void Roseira::beleza() {
    std::cout << "Bonita" << std::endl;
}


void Roseira::cresce() {
    std::cout << "Neutra" << std::endl;
}

void Roseira::mostrarInfoPlanta() const {

}