//
// Created by bruni on 27/10/2025.
//

#ifndef LAREA_H
#define LAREA_H

#include "Comandos/Comando.h"

class LArea : public Comando {
public:
    LArea(int );

    void executa() override;
};



#endif //LAREA_H
