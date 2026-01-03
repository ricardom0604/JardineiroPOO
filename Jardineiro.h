//
// Created by bruni on 24/10/2025.
//
#ifndef JARDINEIRO_H
#define JARDINEIRO_H
#include "Posicao.h"
#include <vector>
class Ferramenta;

class Jardineiro {
    Posicao pos;

    Ferramenta* naMao = nullptr;
    std::vector<Ferramenta*> inventario;
public:

    Jardineiro(int l ,int c) : pos(l,c) {}
    ~Jardineiro();
    //====GETTERS====
    Posicao getPosicao() const;
    //====SETTERS====

    void setPosicao(int l,int c);
    bool mover(char direcao, int maxL, int maxC);

    bool temFerramenta() const { return naMao != nullptr; }
    Ferramenta* getFerramenta() const { return naMao; }

    bool pegaFerramenta(Ferramenta* f);
    Ferramenta* largaFerramenta();

    void listarFerramentas() const;

    void colher();
    void plantar();
    void regar();
    void fertilizar();
    void podar();
    void usarFerramenta(char tipo);

    const std::vector<Ferramenta*>& getInventario() const { return inventario; }

    bool adicionaAoInventario(Ferramenta* f) {
        if (!f) return false;
        inventario.push_back(f);
        return true;
    }

    bool equipaDoInventario(int n);   // n começa em 1
    int inventarioTamanho() const { return (int)inventario.size(); }

};

#endif //JARDINEIRO_H