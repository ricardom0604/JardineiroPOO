//
// Created by bruni on 24/10/2025.
//

#include "Solo.h"
#include <cctype>


//Construtor padrão
Solo::Solo(): planta(nullptr) {
    agua = 80 + rand() % 21;        // [80, 100]
    nutrientes = 40 + rand() % 11;  // [40, 50]
}

//Contrutor com a posição
Solo::Solo(const Posicao& posicao) : p(posicao), planta(nullptr) {
    agua = 80 + rand() % 21;
    nutrientes = 40 + rand() % 11;
}

//Construtor de letras
Solo::Solo(char l, char c) : planta(nullptr) {
    p.setL(l - 'A');
    p.setC(c - 'A');
    agua = 80 + rand() % 21;
    nutrientes = 40 + rand() % 11;
}

//Destrutor
Solo::~Solo() { delete planta;}

//====GETTERS====
Planta* Solo::getPlanta() {return planta;}

Posicao Solo::getposicao() {return p;}

int Solo::getAgua() {return agua;}

int Solo::getNutrientesSolo() {return nutrientes;}

bool Solo::temPlanta() {return planta != nullptr;}

//====SETTERS====
bool Solo::setPlanta(Planta *novaPlanta) {  //Verifica se já está ocupada e retorna sucesso/falha
   if(planta == nullptr) {
       planta = novaPlanta;
       return true;
   }
    return false;
}

Planta* Solo::removePlanta() {
    Planta* temp = planta;
    planta = nullptr;
    return temp;
}
