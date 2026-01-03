#include "ErvaDaninha.h"
#include "Jardim.h"
#include "Settings.h"
#include "Solo.h"

#include <algorithm> // std::min
#include <iostream>

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
    int absorcaoAgua = std::min(+Settings::ErvaDaninha::absorcao_agua, aguaSolo);
    if (absorcaoAgua > 0) {
        solo.retiraAgua(absorcaoAgua);
        agua += absorcaoAgua;
    }

    // Absorção de Nutrientes (1 unidade, se existir)
    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = std::min(+Settings::ErvaDaninha::absorcao_nutrientes, nutrientesSolo);
    if (absorcaoNutrientes > 0) {
        solo.retiraNutrientes(absorcaoNutrientes);
        nutrientes += absorcaoNutrientes;
    }
}

bool ErvaDaninha::verificaMorte(const Solo& /*solo*/) const {
    // morre sozinha passado 60 instantes
    return contadorInstantes >= Settings::ErvaDaninha::morre_instantes;
}

void ErvaDaninha::acaoMorte(Solo& /*solo*/) {
}

Planta* ErvaDaninha::tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) {
    // Regra: Nutrientes > 30 e passaram 5 instantes desde a última vez
    if (nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
        instantesDesdeUltimaMultiplicacao >= Settings::ErvaDaninha::multiplica_instantes) {

        Posicao destino;
        if (jardim.obterVizinhoQualquer(minhaPosicao, destino)) {
            instantesDesdeUltimaMultiplicacao = 0;

            // A lógica de "matar" quem lá está deve ser executada no Jardim::avanca
            return new ErvaDaninha();
        }
        }
    return nullptr;
}


void ErvaDaninha::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: ErvaDaninha\n";
}