//
// Created by bruni on 23/10/2025.
//

#include "Planta.h"


Planta::Planta(float agua, int nutrientes, string beleza, char character):agua(agua), nutrientes(nutrientes),tipoBeleza(tipoBeleza), character(character){
}

//===GETTERS===
int Planta::getAgua() {return agua;}

int Planta::getNutri() {return nutrientes;}

string Planta::getBeleza() {return tipoBeleza;}

char Planta::getChar() {return character;}

//===SETTERS===
void Planta::setAgua(int a) {agua = a;}

void Planta::setNutri(int n) {nutrientes = n;}

void Planta::setBeleza(string b) {tipoBeleza = b;}

void Planta::setChar(char c) {character = c;}

void Planta::cresce() {}

void Planta::mostrarInfoPlanta() const {
    std::cout << "Planta: " << character << "\n"
              << "  Beleza: " << tipoBeleza << "\n"
              << "  Agua: " << agua << "\n"
              << "  Nutrientes: " << nutrientes << "\n";
}


