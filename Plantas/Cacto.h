//
// Created by bruni on 23/10/2025.
//

#ifndef CACTO_H
#define CACTO_H
#include "Planta.h"


class Cacto : public Planta{
    int contaInstantesAgua = 0;
    int contaInstantesNutrientes = 0;
public:

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;
};



#endif //CACTO_H
