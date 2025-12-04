//
// Created by bruni on 23/10/2025.
//

#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include <string>
#include <bits/basic_string.h>

using namespace std;

class Ferramenta{
    int nSerie;
    char character;
    string nome;
public:
    Ferramenta();

    Ferramenta(__resharper_unknown_type nome, char character);

    Ferramenta(string nome, char character);

    int getnSerie() const;

    char getCharacter() const;

    string getNome() const;

    //===GETTERS===
    int getnSerie();
    char getCharacter();
    string getNome();

    //===SETTERS===
    void setnSerie(int nSerie);
    void setCharacter(char c);
    void setNome(string n);

    virtual void usar();
    virtual void mostrarInfo();



};




#endif //FERRAMENTA_H
