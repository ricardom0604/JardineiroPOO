#include "Jardim.h"



#include "Jardineiro.h"
#include "Roseira.h"
#include "Solo.h"


Jardim::Jardim(int l, int c) : l(l), c(c) {
    mapa = new Solo*[l];             //cria vetor de l ponteiro um para cada linha
    for (int i = 0; i < l; i++) {
        mapa[i] = new Solo[c];         //para cada linha cria um array de char,
        for (int j = 0; j < c; j++) {
            mapa[i][j].setPlanta(nullptr);
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
        for (int j = 0; j < c; j++) {
            char c = mapa[i][j].getPlanta()->getChar();
            printf(" %c ", c);
        }
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

void Jardim::planta(char l, char c, char tipo){
    int linha = l - 'A';
    int coluna = c - 'A';

    Planta *p;
    switch (tipo) {
        case 'r':
            p = new Roseira();
        default:
            p = new Planta();
    }

    mapa[linha][coluna].setPlanta(p);
}


