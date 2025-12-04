//
// Created by bruni on 23/10/2025.
//

#ifndef EXOTICA_H
#define EXOTICA_H
#include "Planta.h"


class Exotica:public Planta {
public:
    Exotica();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;
};



#endif //EXOTICA_H
