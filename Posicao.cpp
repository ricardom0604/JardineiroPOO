//
// Created by bruni on 11/12/2025.
//

#include "Posicao.h"
#include <iostream>


Posicao::Posicao(int linha, int coluna) : l(linha), c(coluna) {}

Posicao::Posicao() : l(0), c(0) {}


// ======GETTERS=====
int Posicao::getL() const {return l;}
int Posicao::getC() const {return c;}

// =====SETTERS=====
void Posicao::setL(int linha) {l = linha;}
void Posicao::setC(int coluna) {c = coluna;}
