#ifndef FERRAMENTAZ_H
#define FERRAMENTAZ_H

#include "Ferramenta.h"

class FerramentaZ : public Ferramenta {
    int usos;
public:
    FerramentaZ();

    void usar(Solo& solo, Jardineiro& jardineiro) override;
    bool estaGasta() const override;
    void mostrarInfo() const override;

    Ferramenta* clona() const override {
        return new FerramentaZ(*this);
    }
};

#endif
