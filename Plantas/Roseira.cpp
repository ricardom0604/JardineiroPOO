//
// Created by bruni on 23/10/2025.
//

#include "Roseira.h"
#include "iostream"
#include "Jardim.h"
#include "Solo.h"

using namespace std;

Roseira::Roseira() :Planta(Settings::Roseira::inicial_agua,Settings::Roseira::inicial_nutrientes, "bonita" ,'r') {
    std::cout << "A construir Roseira \n" << std::endl;
}

void Roseira::beleza() {std::cout << "Bonita" << std::endl;}

void Roseira::cresce() { }


void Roseira::cadaInstante(Solo &solo) {
    contadorInstantes ++;

    agua -= Settings::Roseira::perda_agua;
    nutrientes -= Settings::Roseira::perda_nutrientes;

    int aguaSolo = solo.getAgua();
    int absorcaoAgua = min((int)Settings::Roseira::absorcao_agua, aguaSolo);
    if (absorcaoAgua > 0) {
        solo.retiraAgua(absorcaoAgua);
        agua += absorcaoAgua;
    }

    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = min((int)Settings::Roseira::absorcao_nutrientes,nutrientesSolo);
    if (absorcaoNutrientes > 0) {
        solo.retiraNutrientes(absorcaoNutrientes);
        nutrientes += absorcaoNutrientes;
    }
}

bool Roseira::verificaMorte(const Solo &solo) const {
    if(agua <= Settings::Roseira::morre_agua_menor) return true;
    if(nutrientes <= Settings::Roseira::morre_nutrientes_menor) return true;
    if(nutrientes >= Settings::Roseira::morre_nutrientes_maior) return true;  // a constante é 199, ent >=200 ou <199
    return false;
}

void Roseira::acaoMorte(Solo &solo) {
    //deixa no solo metade dos nutrientes e metade da agua
    solo.adicionaNutrientes(nutrientes / 2.0f);
    solo.adicionaAgua(agua / 2.0f);
}


Planta* Roseira::tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) {

    if(nutrientes > Settings::Roseira::multiplica_nutrientes_maior) {
        Posicao destino;
        bool vizinhoEncontrado = jardim.encontraVizinho(minhaPosicao, destino);

        if(vizinhoEncontrado) {
            float novaAgua = agua * (Settings::Roseira::nova_agua_percentagem / 100.0f );

            // A roseira original fica com os novos valores (conforme o enunciado)
            nutrientes = Settings::Roseira::original_nutrientes;
            agua -= novaAgua;

            //Criação da Nova Planta
            Roseira *novaRoseira = new Roseira();
            novaRoseira->setNutri(Settings::Roseira::nova_nutrientes);
            novaRoseira->setAgua(novaAgua);

            return novaRoseira;
        }
    }
    return nullptr;
}

void Roseira::mostrarInfoPlanta() const {}

