//
// Created by bruni on 23/10/2025.
//

#ifndef CACTO_H
#define CACTO_H
#include "Planta.h"


class Cacto : public Planta{
public:

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;
};



#endif //CACTO_H
