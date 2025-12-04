//
// Created by bruni on 23/10/2025.
//

#include "ErvaDaninha.h"

#include "Settings.h"

ErvaDaninha::ErvaDaninha() :Planta(Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia",'e') {

}


void ErvaDaninha::beleza() {
    std::cout << "Feia" << std::endl;
}


void ErvaDaninha::cresce() {
    std::cout << "Neutra" << std::endl;
}

void ErvaDaninha::mostrarInfoPlanta() const {

}