#include <iostream>
#include "Comando.h"
#include <sstream>

using namespace std;

Comando::Comando(Jardim* &jardim) {
    std::string input;
    bool valido = false;
    int l, c;

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

    jardim = new Jardim(l,c);
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
    std::cout << "\n==========================/LISTA DE COMANDOS/==========================================\n";
    std::cout << "-avanca            -lplantas     -colhe <l> <c>            -grava <nome>\n";
    std::cout << "-entra <l> <c>     -lplanta      -planta <l> <c> <tipo>    -recupera <nome>\n";
    std::cout << "-sai               -larea        -larga                    -apaga <nome>\n";
    std::cout << "                   -lsolo        -pega <n>                 -executa <nome-do-ficheiro>\n";
    std::cout << "                   -lferr        -compra <n>               -fim\n";
    std::cout << "=========================================================================================\n";
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
        std::cout << "Fim do programa\n\nTrabalho Feito por:  Bruna Alves de Sousa   N 2022139713\n                     Ricardo Antonio Ribeiro Miguel   N 2022135245\n";
        return false;
    }else {
        std::cout << "\nComando Invalido! Use um da Lista de Comandos.\n";
    }
    return true;//fim
}