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

void Solo::retiraAgua(int x) {
    if (x < 0) return;
    agua -= x;
    if (agua < 0) agua = 0;
}

// Adiciona água ao solo
void Solo::adicionaAgua(float x) {
    if (x <= 0) return;
    agua += (int)std::round(x);
}

// Retira nutrientes
void Solo::retiraNutrientes(int x) {
    if (x < 0) return;
    nutrientes -= x;
    if (nutrientes < 0) nutrientes = 0;
}

// Adiciona nutrientes
void Solo::adicionaNutrientes(float x) {
    if (x <= 0) return;
    nutrientes += (int)std::round(x);
}

bool Solo::eValido(char l, char c) {
    l = (char)std::tolower((unsigned char)l);
    c = (char)std::tolower((unsigned char)c);

    return (l >= 'a' && l <= 'z' && c >= 'a' && c <= 'z');
}