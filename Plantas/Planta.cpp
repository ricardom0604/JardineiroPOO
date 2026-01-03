#include "Planta.h"

#include <iostream>


Planta::Planta(float agua, int nutrientes, std::string beleza, char character):character(character), agua(agua), nutrientes(nutrientes), tipoBeleza(beleza), contadorInstantes(0){
}

//===GETTERS===
int Planta::getAgua() {return agua;}

int Planta::getNutri() {return nutrientes;}

std::string Planta::getBeleza() {return tipoBeleza;}

char Planta::getChar() {return character;}

//===SETTERS===
void Planta::setAgua(int a) {agua = a;}

void Planta::setNutri(int n) {nutrientes = n;}

void Planta::setBeleza(std::string b) {tipoBeleza = b;}

void Planta::setChar(char c) {character = c;}


void Planta::mostrarInfoPlanta() const {
    std::cout << "  Planta: " << character << "\n"
              << "  Beleza: " << tipoBeleza << "\n"
              << "  Agua: " << agua << "\n"
              << "  Nutrientes: " << nutrientes << "\n";
}


