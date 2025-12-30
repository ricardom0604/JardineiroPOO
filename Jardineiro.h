//
// Created by bruni on 24/10/2025.
//
#ifndef JARDINEIRO_H
#define JARDINEIRO_H
#include "Posicao.h"

class Jardineiro {
    Posicao pos;
public:

    Jardineiro(int l ,int c) : pos(l,c) {}

    //====GETTERS====
    Posicao getPosicao() const;
    //====SETTERS====

    void setPosicao(int l,int c);
    bool mover(char direcao, int maxL, int maxC);

    void colher();
    void plantar();
    void regar();
    void fertilizar();
    void podar();
    void usarFerramenta(char tipo);

};

#endif //JARDINEIRO_H