//
// Created by bruni on 23/10/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "../Plantas/Planta.h"


class Roseira : public Planta{
public:
    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;
};


#endif //ROSEIRA_H
