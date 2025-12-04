//
// Created by bruni on 23/10/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Settings.h"
#include "../Plantas/Planta.h"


class Roseira : public Planta{
public:

    Roseira();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;
};


#endif //ROSEIRA_H
