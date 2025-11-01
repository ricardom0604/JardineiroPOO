#include "Jardim.h"



#include "Jardineiro.h"


Jardim::Jardim(int l, int c) : l(l), c(c) {
    mapa = new char*[l];
    for (int i = 0; i < l; i++) {
        mapa[i] = new char[c];
        for (int j = 0; j < c; j++) {
            mapa[i][j] = ' ';
        }
    }
}

Jardim::~Jardim() {
    for (int i = 0; i < l; i++)
        delete[] mapa[i];
    delete[] mapa;
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
