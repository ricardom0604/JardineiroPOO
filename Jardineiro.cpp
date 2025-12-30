//
// Created by bruni on 24/10/2025.
//

#include "Jardineiro.h"
#include "Jardim.h"
#include "Solo.h"
#include "Posicao.h"
#include "Ferramentas/Ferramenta.h"
#include <iostream>


//======GETTERS=====
Posicao Jardineiro::getPosicao() const {return pos;}

//======SETTERS=====
void Jardineiro::setPosicao(int l, int c) {
    pos.setL(l);
    pos.setC(c);
}

// ==== MÉTODOS DE AÇÃO ====

// No Jardineiro.cpp
bool Jardineiro::mover(char direcao, int maxL, int maxC) {
    int l = pos.getL();
    int c = pos.getC();

    switch (std::tolower(direcao)) {
        case 'n': l--; break; // Norte
        case 's': l++; break; // Sul
        case 'e': c++; break; // Este
        case 'o': c--; break; // Oeste
        default: return false;
    }

    // Verificar se não sai do jardim (0 a max-1)
    if (l >= 0 && l < maxL && c >= 0 && c < maxC) {
        setPosicao(l, c);
        return true;
    }
    return false;
}

void Jardineiro::regar() {
    // Esta lógica será chamada quando o jardineiro usar o Regador
    std::cout << "Jardineiro a regar a posicao atual...\n";
}

void Jardineiro::fertilizar() {
    std::cout << "Jardineiro a colocar adubo...\n";
}

void Jardineiro::podar() {
    std::cout << "Jardineiro a podar plantas feias...\n";
}

void Jardineiro::colher() {
    std::cout << "Jardineiro a colher frutos/flores...\n";
}

void Jardineiro::plantar() {
    std::cout << "Jardineiro a plantar...\n";
}

void Jardineiro::usarFerramenta(char tipo) {
    std::cout << "Jardineiro a tentar usar ferramenta do tipo: " << tipo << "\n";
}

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



