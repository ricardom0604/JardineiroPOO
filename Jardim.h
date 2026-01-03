#ifndef JARDIM_H
#define JARDIM_H

#include "Jardineiro.h"

class Solo;
class Planta;
class Ferramenta;
class Posicao;

class Jardim {
    int l, c;
    Solo** mapa;
    Jardineiro* jardineiro;

    int numPlantas;
    int numFerramentas;
    Planta** plantas;
    Ferramenta** ferramentas;

    // Métodos privados auxiliares para gestão interna
    void colocarFerramentaAleatoria(); //

public:
    Jardim(int l, int c);
    Jardim(const Jardim& outro);
    ~Jardim();

    Solo& getSolo(int linha, int coluna);
    const Solo& getSolo(int linha, int coluna) const;

    Solo& getSolo(const Posicao& p);
    const Solo& getSolo(const Posicao& p) const;

    //====GETTERS==
    int getLinhas() const { return l; }
    int getColunas() const { return c; }

    bool temJardineiro() const { return jardineiro != nullptr; }
    Jardineiro* getJardineiro() const { return jardineiro; }

    bool entraJardineiro(char lChar, char cChar);
    bool compra(char tipo);

    void avanca(int n);

    bool colhe(char lChar, char cChar);

    void mostra();
    void mostraPlantas() const;
    void listaArea() const;
    void apanhaFerramentaSeExistir(); // após entrar/mover

    void saiJardineiro();
    void listaPlantas() const;

    void planta(char l, char c, char tipo);
    bool encontraVizinho(const Posicao& minhaPosicao, Posicao& destino) const;
    bool obterVizinhoQualquer(const Posicao& minhaPosicao, Posicao& destino) const;


};

#endif