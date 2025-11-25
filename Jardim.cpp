#include "Jardim.h"



#include "Jardineiro.h"


Jardim::Jardim(int l, int c) : l(l), c(c) {
    mapa = new char*[l];             //cria vetor de l ponteiro um para cada linha
    for (int i = 0; i < l; i++) {
        mapa[i] = new char[c];         //para cada linha cria um array de char,
        for (int j = 0; j < c; j++) {
            mapa[i][j] = ' ';
        }
    }

    numPlantas = 0;
    numFerramentas = 0;
    plantas = new Planta*[numPlantas];
    ferramentas = new Ferramenta*[numFerramentas];
}

Jardim::~Jardim() {
    for (int i = 0; i < l; i++)
        delete[] mapa[i];
    delete[] mapa;
    delete []ferramentas;
    delete []plantas;
}

void Jardim::mostra() {
    printf("   ");
    for (int i = 0; i < c; i++)
        printf(" %c ", ('A' + i));
    printf("\n  ");
    for (int i = 0; i < c; i++)
        printf("---");
    printf("--\n");

    for (int i = 0; i < l; i++) {
        printf("%c |", ('A' + i));
        for (int j = 0; j < c; j++)
            printf(" %c ", mapa[i][j]);
        printf("|\n");
    }

    printf("  -");
    for (int i = 0; i < c; i++)
        printf("---");
    printf("-\n");
}

void Jardim::mostraPlantas() const {
    for (int i = 0; i < numPlantas; i++)
        plantas[i]->mostrarInfoPlanta();
}

void Jardim::planta(int l, int c, char tipo){
    mapa[l][c] = tipo;
}


