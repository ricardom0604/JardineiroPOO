//
// Created by bruni on 23/10/2025.
//

#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include <string>

#include "Jardineiro.h"

using namespace std;
class Solo;

class Ferramenta{
protected:
    static int contadorNS;
    int nSerie;
    char character;
    string nome;
public:
    Ferramenta(const string &nome, char c);
    virtual ~Ferramenta();

    //===GETTERS===
    int getnSerie() const;
    char getChar() const;
    string getNome() const;

    //===SETTERS===
    void setnSerie(int nSerie);
    void setChar(char c);
    void setNome(string n);

    virtual void usar(Solo &solo, Jardineiro& jardineiro) = 0;
    virtual bool estaGasta() const = 0;
    virtual void mostrarInfo() const;



};

#endif //FERRAMENTA_H
