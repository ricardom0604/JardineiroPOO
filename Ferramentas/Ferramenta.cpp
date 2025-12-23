//
// Created by bruni on 23/10/2025.
//

#include "Ferramenta.h"

#include <iostream>
#include <string>

using namespace std;
int Ferramenta::contadorNS = 1;

Ferramenta::Ferramenta(char c, const std::string &nomeFerramenta)
        : character(c), nome(nomeFerramenta) {
    nSerie = contadorNS++;  // atribui número de série único
}

//===GETTERS===
int Ferramenta::getnSerie()const {return nSerie;}

char Ferramenta::getCharacter()const {return character;}

string Ferramenta::getNome()const {return nome;}


void Ferramenta::mostrarInfo() const {
    std::cout << "Ferramenta: " << nome
              << " | Série: " << nSerie
              << " | Char: '" << character << "'\n";
}



