#include "Jardineiro.h"
#include "Jardim.h"
#include "Solo.h"
#include "Posicao.h"
#include "Ferramentas/Ferramenta.h"
#include <iostream>

Jardineiro::~Jardineiro() {
    // apagar ferramenta na mão
    delete naMao;
    naMao = nullptr;

    // apagar ferramentas do inventário
    for (Ferramenta* f : inventario) {
        delete f;
    }
    inventario.clear();
}


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

bool Jardineiro::pegaFerramenta(Ferramenta* f) {
    if (!f) return false;

    // se não tiver nada na mão -> vai para a mão
    if (naMao == nullptr) {
        naMao = f;
        return true;
    }

    // senão, vai para a mochila
    inventario.push_back(f);
    return true;
}

Ferramenta* Jardineiro::largaFerramenta() {
    Ferramenta* temp = naMao;
    naMao = nullptr;
    return temp;
}

void Jardineiro::listarFerramentas() const {
    if (naMao) {
        std::cout << "[MAO] ";
        naMao->mostrarInfo();
    } else {
        std::cout << "[MAO] (vazio)\n";
    }

    if (inventario.empty()) {
        std::cout << "[INV] (vazio)\n";
    } else {
        for (size_t i = 0; i < inventario.size(); i++) {
            if (!inventario[i]) {
                std::cout << "[INV " << (i + 1) << "] (nullptr)\n";
                continue;
            }
            std::cout << "[INV " << (i + 1) << "] ";
            inventario[i]->mostrarInfo();
        }
    }
}


bool Jardineiro::equipaDoInventario(int n) {
    // n é 1..size
    if (n <= 0 || n > (int)inventario.size()) return false;

    Ferramenta* escolhida = inventario[n - 1];

    // remove do inventário (mantendo ordem)
    inventario.erase(inventario.begin() + (n - 1));

    // swap: a da mão vai para inventário (se existir)
    if (naMao != nullptr) {
        inventario.push_back(naMao);
    }

    naMao = escolhida;
    return true;
}




