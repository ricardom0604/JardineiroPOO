//
// Created by bruni on 23/10/2025.
//

#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Settings.h"
#include "../Plantas/Planta.h"


class Jardim;

class Roseira : public Planta{
public:

    Roseira(): Planta(Settings::Roseira::inicial_agua, Settings::Roseira::inicial_nutrientes, "bonita", 'r'){};

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo& solo) override;
    bool verificaMorte(const Solo &solo) const override;
    void acaoMorte(Solo &solo) override;

    Planta* tentaMultiplicar(Jardim &jardim, const Posicao &minhaPosicao) override; //Planta* acaoMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;




#endif //ROSEIRA_H
