//
// Created by bruni on 24/10/2025.
//

#include "Solo.h"

#include <cctype>

Solo::Solo() {

}

Solo::Solo(int l, int c) : l(l), c(c) {
}
Solo::Solo(char l, char c) {
    this->l = l-'A';
    this->c = c-'A';
}
Solo::~Solo() {
}


int Solo::getL() {
    return l;
}
void Solo::setL(int l) {
    this->l=l;
}
int Solo::getC() {
    return c;
}
void Solo::setC(int c) {
    this->c=c;
}

bool Solo::eValido(char l, char c) {
    return std::tolower(l) >= 'a' && std::tolower(l) <= 'z' && std::tolower(c) >= 'a' && std::tolower(c) <= 'z';
}

Planta* Solo::getPlanta() {
    return planta;
}

void Solo::setPlanta(Planta *planta) {
    planta = planta;
}
