#ifndef REGADOR_H
#define REGADOR_H

#include "Ferramenta.h"
#include "Settings.h"

class Regador : public Ferramenta {
    int aguaAtual;

public:
    Regador() : Ferramenta("Regador", 'g'), aguaAtual(Settings::Regador::capacidade) {}

    void usar(Solo& solo, Jardineiro& jardineiro) override;

    bool estaGasta() const override;

    void mostrarInfo() const override;
};

#endif