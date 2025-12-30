//
// Created by bruni on 23/10/2025.
//

#include "Ferramenta.h"
#include <iostream>
#include <string>

using namespace std;
int Ferramenta::contadorNS = 1;

Ferramenta::Ferramenta(const std::string &nomeFerramenta, char c)
        : nome(nomeFerramenta) , character(c) {
    nSerie = contadorNS++;  // atribui número de série único
}

Ferramenta:: ~Ferramenta(){}

//===GETTERS===
int Ferramenta::getnSerie()const {return nSerie;}

char Ferramenta::getChar()const {return character;}

string Ferramenta::getNome()const {return nome;}


void Ferramenta::mostrarInfo() const {
    std::cout << "Ferramenta: " << nome
              << " | Série: " << nSerie
              << " | Char: '" << character << "'\n";
}



