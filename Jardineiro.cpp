//
// Created by bruni on 24/10/2025.
//

#include "Jardineiro.h"
#include "Jardim.h"
#include "Solo.h"
#include "Posicao.h"
#include "Ferramentas/Ferramenta.h"

// Construtor
Jardineiro::Jardineiro() {}

/*
// Regar o Solo na posição 'p'
void Jardineiro::regar(Jardim& jardim, const Posicao& p) {
    Solo& soloAlvo = jardim.getSolo(p);
    int quantidadeAgua = 10; // Valor fixo ou Settings

    // Adicionar água ao Solo
    soloAlvo.regarsolo(quantidadeAgua);

    std::cout << "Regou o solo em " << p.getCharL() << p.getCharC() << " com "
              << quantidadeAgua << " unidades de água.\n";
}

// Podar a Planta na posição 'p'
void Jardineiro::podar(Jardim& jardim, const Posicao& p) {
    Solo& soloAlvo = jardim.getSolo(p);

    if (soloAlvo.temPlanta()) {
        soloAlvo.getPlanta()->podar(); //

        std::cout << "Podou a planta em " << p.getCharL() << p.getCharC() << ".\n";
    } else {
        std::cout << "Não há planta para podar nesta posição.\n";
    }
}
*/



