//
// Created by bruni on 23/10/2025.
//

#include "Ferramenta.h"

#include <string>


using namespace std;

Ferramenta::Ferramenta(string nome, char character): nome(nome), character(character) {

}

//===GETTERS===
int Ferramenta::getnSerie()const {
    return nSerie;
}

char Ferramenta::getCharacter()const {
    return character;
}

string Ferramenta::getNome()const {
    return nome;
}






