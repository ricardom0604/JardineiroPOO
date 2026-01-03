#ifndef CACTO_H
#define CACTO_H

#include "Planta.h"

class Cacto : public Planta {
private:
    int contaInstantesAgua;
    int contaInstantesNutrientes;

public:
    Cacto();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo& solo) override;
    bool verificaMorte(const Solo& solo) const override;
    void acaoMorte(Solo& solo) override;

    Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;

    Planta* clona() const override {
        return new Cacto(*this); // Cria uma cópia real de si mesmo
    }
};

#endif // CACTO_H
