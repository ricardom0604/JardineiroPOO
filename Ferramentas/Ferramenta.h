//
// Created by bruni on 23/10/2025.
//

#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include <string>

using namespace std;
class Solo;

class Ferramenta{
protected:
    static int contadorNS;
    int nSerie;
    char character;
    string nome;
public:
    Ferramenta(char c, const string &nome);
    virtual ~Ferramenta() = default;

    //===GETTERS===
    int getnSerie() const;
    char getCharacter() const;
    string getNome() const;

    //===SETTERS===
    void setnSerie(int nSerie);
    void setCharacter(char c);
    void setNome(string n);

    virtual void usar(Solo &solo, int l, int c) = 0;

    virtual void mostrarInfo() const;



};

#endif //FERRAMENTA_H
