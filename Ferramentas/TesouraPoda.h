#ifndef TESOURAPODA_H
#define TESOURAPODA_H

#include "Ferramenta.h"

class TesouraPoda : public Ferramenta {
public:
    TesouraPoda() : Ferramenta("Tesoura de Poda", 't') {}

    void usar(Solo& solo, Jardineiro& jardineiro) override;

    bool estaGasta() const override;

    void mostrarInfo() const override;

    Ferramenta* clona() const override {
        return new TesouraPoda(*this);
    }
};

#endif