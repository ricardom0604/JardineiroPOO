//
// Created by bruni on 23/10/2025.
//

#ifndef ERVADANINHA_H
#define ERVADANINHA_H
#include "Planta.h"


class ErvaDaninha : public Planta {
public:
    void cresce() override;
    void mostrarInfoPlanta() const override;
};



#endif //ERVADANINHA_H
