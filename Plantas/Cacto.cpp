#include "Cacto.h"
#include "Solo.h"
#include "Settings.h"

#include <iostream>
#include <cmath>
#include <algorithm> // std::min



Cacto::Cacto()
    : Planta(0, 0, "neutra", 'c'),
      contaInstantesAgua(0),
      contaInstantesNutrientes(0) {
}

void Cacto::beleza() {
    std::cout << "Neutra\n";
}

void Cacto::cresce() {
}

void Cacto::cadaInstante(Solo& solo) {
    contadorInstantes++;

    // --- Absorção de água (25% do solo) ---
    int aguaSolo = solo.getAgua();
    int absorcaoAgua = (int)std::round(
        aguaSolo * Settings::Cacto::absorcao_agua_percentagem / 100.0f
    );
    absorcaoAgua = std::min(absorcaoAgua, aguaSolo);

    if (absorcaoAgua > 0) {
        solo.retiraAgua(absorcaoAgua);
        agua += absorcaoAgua;
    }

    //  Absorção de nutrientes (até 5 unidades)
    int nutrientesSolo = solo.getNutrientesSolo();
    int absorcaoNutrientes = std::min(+Settings::Cacto::absorcao_nutrientes, nutrientesSolo);  //"+" força a passagem por valor, evitando um erro de 'undefined reference' no linker, já que o std::min espera uma referência (&)

    if (absorcaoNutrientes > 0) {
        solo.retiraNutrientes(absorcaoNutrientes);
        nutrientes += absorcaoNutrientes;
    }

    // Contadores para morte
    if (aguaSolo > Settings::Cacto::morre_agua_solo_maior)
        contaInstantesAgua++;
    else
        contaInstantesAgua = 0;

    if (nutrientesSolo <= Settings::Cacto::morre_nutrientes_solo_menor)
        contaInstantesNutrientes++;
    else
        contaInstantesNutrientes = 0;
}

bool Cacto::verificaMorte(const Solo& /*solo*/) const {
    if (contaInstantesAgua >= Settings::Cacto::morre_agua_solo_instantes)
        return true;

    if (contaInstantesNutrientes > Settings::Cacto::morre_nutrientes_solo_instantes)
        return true;

    return false;
}

void Cacto::acaoMorte(Solo& solo) {
    solo.adicionaNutrientes(nutrientes);
}

Planta* Cacto::tentaMultiplicar(Jardim& /*jardim*/, const Posicao& /*minhaPosicao*/) {
    return nullptr;
}

void Cacto::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: Cacto\n";
}
