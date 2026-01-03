#ifndef ROSEIRA_H
#define ROSEIRA_H

#include "Settings.h"
#include "Planta.h"   // ajusta o include ao teu caminho real

class Jardim;
class Solo;

class Roseira : public Planta {
public:
    Roseira();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo& solo) override;
    bool verificaMorte(const Solo& solo) const override;
    void acaoMorte(Solo& solo) override;

    Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;

    Planta* clona() const override {
        return new Roseira(*this); // Cria uma cópia real de si mesmo
    }
};

#endif // ROSEIRA_H
