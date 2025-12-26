#ifndef JARDIM_H
#define JARDIM_H

#include <iostream>

class Solo;
class Planta;
class Ferramenta;
class Posicao;

class Jardim {
    int l, c;
    Solo** mapa;

    int numPlantas;
    int numFerramentas;
    Planta** plantas;
    Ferramenta** ferramentas;

public:
    Jardim(int l, int c);
    ~Jardim();

    void mostra();
    void mostraPlantas() const;

    void planta(char l, char c, char tipo);
    bool encontraVizinho(const Posicao& minhaPosicao, Posicao& destino) const;

    // (recomendado para validação futura)
    int getLinhas() const { return l; }
    int getColunas() const { return c; }
};

#endif
