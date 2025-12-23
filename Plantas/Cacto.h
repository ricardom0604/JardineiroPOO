//
// Created by bruni on 23/10/2025.
//

#ifndef CACTO_H
#define CACTO_H
#include "Planta.h"
#include "Settings.h"


class Cacto : public Planta{
private:
    int contaInstantesAgua;
    int contaInstantesNutrientes;
public:

    Cacto(); //valores de agua e nutrientes dados por mim

    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo &solo) override;
    bool verificaMorte(const Solo &solo) const override;
    void acaoMorte(Solo &solo) override;
    //Planta* acaoMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;
};



#endif //CACTO_H
