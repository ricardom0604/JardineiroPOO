//
// Created by bruni on 23/10/2025.
//

#ifndef FERRAMENTAZ_H
#define FERRAMENTAZ_H

#include "Ferramenta.h"

class FerramentaZ : public Ferramenta {
public:
    FerramentaZ();

    // Apenas a declaração terminada em ;
    void usar(Solo& solo, Jardineiro& jardineiro) override;
    bool estaGasta() const override;
    void mostrarInfo() const override;
};

#endif
