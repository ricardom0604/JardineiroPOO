//
// Created by bruni on 27/10/2025.
//

#include <iostream>
#include "Comando.h"
#include <sstream>

using namespace std;

Comando::Comando() {
}
Comando::~Comando() {
}
std::string Comando::obtemInput(std::string message) {
    std::string input;

    std::cout << message << "\n> ";
    std::getline(std::cin, input);

    return input;
}

bool Comando::executa() {
    std::string input;
    std::cout << "\nIntroduza:\n";
    std::cout << "-avanca     \n-lplantas\nlplanta <l> <c> puto olha a stora... ";
    std::cout << "-lplantas\n-lplantas\nlplanta <l><c> puto olha a stora...  ";
    std::cout << "-lplanta <l> <c>   -lplantas\nlplanta <l><c> puto olha a stora... ";
    std::cout << "-larea     -lplantas  lplanta <l><c> puto olha a stora...  ";
    std::cout << "-lsolo <l> <c> [n]\n-lplantas\nlplanta <l><c> puto olha a stora... \n\n";
    input = obtemInput("Comando:");

    std::istringstream iss(input);
    iss >> input ;

    if (input == "avanca") {
        std::cout << "\nAvanca\n";
    }else if (input == "lplantas") {
        std::cout << "\nLista de Plantas:\n";
    }else if (input == "lplanta") {
        std::cout << "\nPropriedades da planta:\n";
    }else if (input == "larea") {
        std::cout << "\nPropriedade e Conteudo da area:\n";
    }else if (input == "lsolo") {
        std::cout << "\nCoisas que se encontram no solo:\n";
    }else if (input == "lferr") {
        std::cout << "\nFerramentas:\n";
    }else if (input == "colhe") {
        std::cout << "\nColhe planta:\n";
    }else if (input == "planta") {
        std::cout << "\nColoca nova planta:\n";
    }else if (input == "larga") {
        std::cout << "\nLarga Ferramenta:\n";
    }else if (input == "pega") {
        std::cout << "\nPega Ferramenta:\n";
    }else if (input == "compra") {
        std::cout << "\nCompra Ferramenta:\n";
    }else if (input == "entra") {
        std::cout << "\nEntra na posicao:\n";
    }else if (input == "sai") {
        std::cout << "\nSai do jardim:\n";
    }else if (input == "grava") {
        std::cout << "\nGrava do programa\n";
    }else if (input == "recupera") {
        std::cout << "\nRecupera programa\n";
    }else if (input == "apaga") {
        std::cout << "\nApaga programa\n";
    }else if (input == "executa") {
        std::cout << "\nExecuta programa\n";
    }else if (input == "fim") {
        std::cout << "\nFim do programa\n";
        return false;
    }
    return true;//fim
}