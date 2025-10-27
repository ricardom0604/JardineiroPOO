//
// Created by bruni on 27/10/2025.
//

#include <iostream>
#include "Comando.h"
#include <sstream>

using namespace std;

Comando::Comando() {
}

Jardim Comando::criaJardim() {
    std::string input;
    int l, c;

    std::cout << "Introduza:\n";
    std::cout << "-jardim <n> <n>\n\nComando: ";
    getline(cin, input);

    istringstream iss(input);
    iss >> input >> l >> c;

    if (!(input == "jardim"))
        return Jardim(10, 10);

    return Jardim(l, c);
}