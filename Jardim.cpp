//
// Created by bruni on 24/10/2025.
//

#include "Jardim.h"



#include "Jardineiro.h"


Jardim::Jardim()  {
    std::string input;
    std::cout << "Introduza o tamanho do jardim:\n";
    std::cout << "-jardim <linha> <coluna>\n\nComando: ";
    getline(std::cin, input);

    std::istringstream iss(input);
    iss >> input >> l >> c;

    if (!(input == "jardim")) {
        l = 10;
        c = 10;
    }

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