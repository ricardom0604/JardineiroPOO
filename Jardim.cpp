//
// Created by bruni on 24/10/2025.
//

#include "Jardim.h"

#include <cstdio>

#include "Jardineiro.h"

Jardim::Jardim() {
}

void Jardim::inicializa() {
    for (int i = 0; i < Settings::Jardim::tamanho; i++) {
        for (int j = 0; j < Settings::Jardim::tamanho; j++) {
            mapa[i][j] = '.';
        }
    }
}

void Jardim::mostra() {
    printf("   ");
    for (int i = 0; i < Settings::Jardim::tamanho; i++)
        printf(" %c ", ('A' + i));
    printf("\n  ");
    for (int i = 0; i < Settings::Jardim::tamanho; i++)
        printf("---");
    printf("--\n");

    for (int i = 0; i < Settings::Jardim::tamanho; i++) {
        printf("%c |", ('A' + i));
        for (int j = 0; j < Settings::Jardim::tamanho; j++)
            printf(" %c ", mapa[i][j]);
        printf("|\n");
    }

    printf("  ");
    for (int i = 0; i < Settings::Jardim::tamanho; i++)
        printf("---");
    printf("--\n");
}