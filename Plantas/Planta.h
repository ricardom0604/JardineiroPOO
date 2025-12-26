#ifndef PLANTA_H
#define PLANTA_H

#include <iostream>
#include <string>
#include "Posicao.h"

class Jardim;
class Solo;

class Planta {
protected:
    char character;
    float agua;
    float nutrientes;
    std::string tipoBeleza;
    int contadorInstantes;

public:
    Planta(float agua, int nutrientes, std::string beleza, char character);
    virtual ~Planta() = default;

    virtual void cadaInstante(Solo& solo) = 0;
    virtual bool verificaMorte(const Solo& solo) const = 0;
    virtual void acaoMorte(Solo& solo) = 0;
    virtual Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) = 0;

    // estes dois existem na tua derivada, então mete-os também na base:
    virtual void beleza() = 0;
    virtual void cresce() = 0;

    // getters
    int getAgua();
    int getNutri();
    std::string getBeleza();
    char getChar();

    void setAgua(int a);
    void setNutri(int n);
    void setBeleza(std::string b);
    void setChar(char c);

    virtual void mostrarInfoPlanta() const;

    bool eFeia() const { return tipoBeleza == "feia"; }
};

#endif // PLANTA_H
