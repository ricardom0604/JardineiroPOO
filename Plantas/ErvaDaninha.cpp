//
// Created by bruni on 23/10/2025.
//

#include "ErvaDaninha.h"

#include "Settings.h"
#include "Solo.h"

using namespace std;

ErvaDaninha::ErvaDaninha() :Planta(Settings::ErvaDaninha::inicial_agua, Settings::ErvaDaninha::inicial_nutrientes, "feia",'e') {

}


void ErvaDaninha::beleza() {std::cout << "Feia" << std::endl;}

void ErvaDaninha::cresce() {}

void ErvaDaninha::cadaInstante(Solo &solo) {
    contadorInstantes ++;
    instantesDesdeUltimaMultiplicacao++;

    //Absorção de Água (1 unidade, se existir)
    int aguaSolo = solo.getAgua();
    int absorcaoAgua = min(Settings::ErvaDaninha::absorcao_agua, aguaSolo);
    if(absorcaoAgua < 0) {
        solo.retiraAgua(absorcaoAgua);
        agua += absorcaoAgua;
    }

    //Absorção de Nutrientes (1 unidade, se existir)
    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = min(Settings::ErvaDaninha::absorcao_nutrientes, nutrientesSolo);
    if(absorcaoNutrientes > 0) {
        solo.retiraNutrientes(absorcaoNutrientes);
        nutrientesSolo += absorcaoNutrientes;
    }
}

bool ErvaDaninha::verificaMorte(const Solo &solo) const {
    //morre sozinha passado 60 instantes
    if(contadorInstantes >= Settings::ErvaDaninha::morre_instantes) {
        return true;
    }
    return false;
}

void ErvaDaninha::acaoMorte(Solo &solo) {}

Planta* ErvaDaninha::tentaMultiplicar(Jardim& jardim, const Solo& minhaPosicao) {
    // Nutrientes > 30 && passados 5 instantes desde a última multiplicação.
    if (nutrientes > Settings::ErvaDaninha::multiplica_nutrientes_maior &&
        instantesDesdeUltimaMultiplicacao >= Settings::ErvaDaninha::multiplica_instantes) {
        //Tenta encontrar vizinho
        Solo vizinhaAlvo = jardim.encontraVizinho(minhaPosicao);

        if (vizinhaAlvo.eValida()) {
            // A nova planta fica com 5 de água e 5 de nutrientes (valores iniciais)
            Planta* novaErva = new ErvaDaninha();

            //Reset do contador
            instantesDesdeUltimaMultiplicacao = 0;

            return novaErva;
        }
    }
    return nullptr;
}


void ErvaDaninha::mostrarInfoPlanta() const {}