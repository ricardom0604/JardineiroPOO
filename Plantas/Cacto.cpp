//
// Created by bruni on 23/10/2025.
//

#include "Cacto.h"
#include "Solo.h"
#include <cmath>

Cacto::Cacto() : Planta(0, 0, "neutra", 'c', contaInstantesAgua(0), contaInstantesNutrientes(0) {};

void Cacto::beleza() {
    std::cout << "Neutra" << std::endl;
}

void Cacto::cresce() {
}

void Cacto::cadaInstante(Solo &solo) {
    contadorInstantes ++;

    float aguaSolo = solo.getAgua();
    //Calcula 25% e arredonda para inteiro
    int absorcaoAgua = (int) ::round(aguaSolo * Settings::Cacto::absorcao_agua_percentagem/ 100.0f);
    absorcaoAgua = min(absorcaoAgua, (int)aguaSolo);  //Ñ absorve mais do que aquilo que existe

    solo.retiraAgua(absorcaoAgua);
    agua += absorcaoAgua;

    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = min()
}

bool Cacto::verificaMorte(const Solo& solo) const {
    // Morre se Água no solo > 100 durante 3 instantes seguidos
    if (contaInstantesAgua >= Settings::Cacto::morre_agua_solo_instantes) {
        return true;
    }

    // Morre se Nutrientes no solo = 0 durante mais do que 3 instantes seguidos.
    if (contaInstantesNutrientes > Settings::Cacto::morre_nutrientes_solo_instantes) {
        return true;
    }

    return false;
}

void Cacto::acaoMorte(Solo& solo) {
    // Deixa no solo todos os nutrientes que absorveu durante a sua vida (água não)
    solo.adicionaNutrientes(nutrientes);
}

Planta* Cacto::tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) {
    // Implementação de multiplicação (Cacto divide recursos)
    return nullptr;
}


void Cacto::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: Cacto \n";
}
