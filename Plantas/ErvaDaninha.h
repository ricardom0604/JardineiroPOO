#ifndef ERVADANINHA_H
#define ERVADANINHA_H
#include "Planta.h"
#include "Settings.h"


class ErvaDaninha : public Planta {
private:
    int instantesDesdeUltimaMultiplicacao;
public:
    ErvaDaninha();

    void beleza() override;
    void cresce() override;
    void mostrarInfoPlanta() const override;

    void cadaInstante(Solo &solo) override;
    bool verificaMorte(const Solo& solo) const override;
    void acaoMorte(Solo& solo) override;

    virtual Planta* tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) override;

    Planta* clona() const override {
        return new ErvaDaninha(*this); // Cria uma cópia real de si mesmo
    }

};



#endif //ERVADANINHA_H
