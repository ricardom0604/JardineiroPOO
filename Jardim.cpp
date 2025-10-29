//
// Created by bruni on 24/10/2025.
//

#include "Jardim.h"



#include "Jardineiro.h"


Jardim::Jardim()  {
    std::string input;
    bool valido = false;

    while (!valido) {
        std::cout << "Introduza o tamanho do jardim:\n";
        std::cout << "-jardim <linha> <coluna>\n\nComando: ";
        getline(std::cin, input);

        std::istringstream iss(input);
        std::string comando;
        iss >> comando >> l >> c;

        if (comando != "jardim") {
            std::cout << "Comando invalido! Use o formato: jardim <linha> <coluna>\n\n";
            continue;
        }

        if (iss.fail()) { // não conseguiu ler números
            std::cout << "Valores invalidos! Introduza numeros inteiros.\n\n";
            continue;
        }

        if (l <= 0 || c <= 0) {
            std::cout << "As dimensoes devem ser positivas.\n\n";
            continue;
        }

        if (l > 26 || c > 26) {
            std::cout << "O tamanho maximo permitido é 26x26.\n";
            std::cout << "Por favor introduza novamente.\n\n";
            continue; // volta ao início do while
        }

        // Se chegou aqui, os valores são válidos
        valido = true;
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