//
// Created by bruni on 24/10/2025.
//

#include "Posicao.h"

#include <cctype>

Posicao::Posicao(int l, int c) : l(l), c(c) {
}
Posicao::Posicao(char l, char c) {
    this->l = l-'A';
    this->c = c-'A';
}
Posicao::~Posicao() {
}


int Posicao::getL() {
    return l;
}
void Posicao::setL(int l) {
    this->l=l;
}
int Posicao::getC() {
    return c;
}
void Posicao::setC(int c) {
    this->c=c;
}

bool Posicao::eValido(char l, char c) {
    return std::tolower(l) >= 'a' && std::tolower(l) <= 'z' && std::tolower(c) >= 'a' && std::tolower(c) <= 'z';
}