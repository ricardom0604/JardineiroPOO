#ifndef PACOTEADUBO_H
#define PACOTEADUBO_H
#include "Ferramenta.h"
#include "Settings.h"

class PacoteAdubo : public Ferramenta {
    int quantidade;

public:
    PacoteAdubo() : Ferramenta("Pacote de Adubo", 'a'),
                    quantidade(Settings::Adubo::capacidade) {} // Inicializa com 100 [cite: 94]

    void usar(Solo& solo, Jardineiro& jardineiro) override;

    bool estaGasta() const override;
    void mostrarInfo() const;
};

#endif