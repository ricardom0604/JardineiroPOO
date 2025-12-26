#include "ErvaDaninha.h"
#include "Jardim.h"
#include "Settings.h"
#include "Solo.h"

#include <algorithm> // std::min
#include <iostream>

// Workaround (não usar diretamente Settings::... que dá undefined reference no MinGW)
static const int ERVA_ABSORCAO_AGUA = 1;       // Settings::ErvaDaninha::absorcao_agua
static const int ERVA_ABSORCAO_NUTR = 1;       // Settings::ErvaDaninha::absorcao_nutrientes

ErvaDaninha::ErvaDaninha()
    : Planta(Settings::ErvaDaninha::inicial_agua,
             Settings::ErvaDaninha::inicial_nutrientes,
             "feia",
             'e'),
      instantesDesdeUltimaMultiplicacao(0) {
}

void ErvaDaninha::beleza() {
    std::cout << "Feia\n";
}

void ErvaDaninha::cresce() {
}

void ErvaDaninha::cadaInstante(Solo& solo) {
    contadorInstantes++;
    instantesDesdeUltimaMultiplicacao++;

    // Absorção de Água (1 unidade, se existir)
    int aguaSolo = solo.getAgua();
    int absorcaoAgua = std::min(ERVA_ABSORCAO_AGUA, aguaSolo);
    if (absorcaoAgua > 0) {
        solo.retiraAgua(absorcaoAgua);
        agua += absorcaoAgua;
    }

    // Absorção de Nutrientes (1 unidade, se existir)
    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = std::min(ERVA_ABSORCAO_NUTR, nutrientesSolo);
    if (absorcaoNutrientes > 0) {
        solo.retiraNutrientes(absorcaoNutrientes);
        nutrientes += absorcaoNutrientes; // aqui era bug no teu: somavas ao "nutrientesSolo"
    }
}

bool ErvaDaninha::verificaMorte(const Solo& /*solo*/) const {
    // morre sozinha passado 60 instantes
    return contadorInstantes >= Settings::ErvaDaninha::morre_instantes;
}

void ErvaDaninha::acaoMorte(Solo& /*solo*/) {
}

Planta* ErvaDaninha::tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) {
    if (nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
        instantesDesdeUltimaMultiplicacao >= Settings::ErvaDaninha::multiplica_instantes) {

        Posicao destino;
        if (jardim.encontraVizinho(minhaPosicao, destino)) {
            instantesDesdeUltimaMultiplicacao = 0;
            return new ErvaDaninha();
        }
    }
    return nullptr;
}

void ErvaDaninha::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: ErvaDaninha\n";
}