//
// Created by bruni on 23/10/2025.
//

#include "Cacto.h"

Cacto::Cacto() : Planta('c', "neutra")
{
    setAgua(0);
    setNutri(0);
}


void Cacto::beleza() {
    std::cout << "Neutra" << std::endl;
}

void Cacto::cresce() {
    std::cout << "Neutra" << std::endl;
}

void Cacto::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: Cacto \n";
}
