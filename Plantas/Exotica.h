//
// Created by bruni on 23/10/2025.
//
#ifndef EXOTICA_H
#define EXOTICA_H

#include "Planta.h"

class Exotica : public Planta {
    char modo;                 // 'r', 'c', 'e' ou 'x'
    int instantesSemVizinhos;  // conta instantes sem vizinhos (para morrer)

public:
    Exotica();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo& solo) override;
    bool verificaMorte(const Solo& solo) const override;
    void acaoMorte(Solo& solo) override;

    // aqui ela “olha” para o jardim e escolhe o modo (camaleão)
    Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;

    Planta* clona() const override {
        return new Exotica(*this); // Cria uma cópia real de si mesmo
    }
};

#endif // EXOTICA_H

