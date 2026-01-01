#include "Exotica.h"
#include "Jardim.h"
#include "Solo.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// constantes locais (não mexe no Settings)
static const int X_SOZINHA_MORRE_APOS = 8;
static const int X_PERDA_AGUA_SOZINHA = 3;
static const int X_PERDA_NUT_SOZINHA  = 2;

Exotica::Exotica()
    : Planta(10, 10, "neutra", 'x'),
      modo('x'),
      instantesSemVizinhos(0) {}

void Exotica::beleza() {
    std::cout << "Camaleao\n";
}

void Exotica::cresce() {
    // não faz nada especial
}

void Exotica::cadaInstante(Solo& solo) {
    contadorInstantes++;

    // se não tem vizinhos (modo atualizado em tentaMultiplicar), vai perdendo recursos
    if (instantesSemVizinhos > 0) {
        agua -= X_PERDA_AGUA_SOZINHA;
        nutrientes -= X_PERDA_NUT_SOZINHA;
        return;
    }

    // imitação simples (sem Settings, para ser estável)
    // r: estilo “forte”
    if (modo == 'r') {
        agua -= 4;
        nutrientes -= 4;

        int a = std::min(5, solo.getAgua());
        if (a > 0) { solo.retiraAgua(a); agua += a; }

        int n = std::min(8, solo.getNutrientesSolo());
        if (n > 0) { solo.retiraNutrientes(n); nutrientes += n; }
        return;
    }

    // e: estilo “erva daninha”
    if (modo == 'e') {
        int a = std::min(1, solo.getAgua());
        if (a > 0) { solo.retiraAgua(a); agua += a; }

        int n = std::min(1, solo.getNutrientesSolo());
        if (n > 0) { solo.retiraNutrientes(n); nutrientes += n; }
        return;
    }

    // c: estilo “cacto”
    if (modo == 'c') {
        int aguaSolo = solo.getAgua();
        int a = std::min((aguaSolo * 25) / 100, aguaSolo);  // 25%
        if (a > 0) { solo.retiraAgua(a); agua += a; }

        int n = std::min(5, solo.getNutrientesSolo());
        if (n > 0) { solo.retiraNutrientes(n); nutrientes += n; }
        return;
    }

    // modo default (x): neutro
    int a = std::min(2, solo.getAgua());
    if (a > 0) { solo.retiraAgua(a); agua += a; }

    int n = std::min(2, solo.getNutrientesSolo());
    if (n > 0) { solo.retiraNutrientes(n); nutrientes += n; }
}

bool Exotica::verificaMorte(const Solo& /*solo*/) const {
    if (agua <= 0 || nutrientes <= 0) return true;
    if (instantesSemVizinhos >= X_SOZINHA_MORRE_APOS) return true;
    return false;
}

void Exotica::acaoMorte(Solo& solo) {
    solo.adicionaNutrientes(nutrientes / 2.0f);
}

// camaleão: escolhe o modo olhando para as plantas vizinhas
Planta* Exotica::tentaMultiplicar(Jardim& jardim, const Posicao& minhaPosicao) {
    modo = 'x';
    instantesSemVizinhos++; // assume que está sozinho, se achar vizinho zera

    int L = minhaPosicao.getL();
    int C = minhaPosicao.getC();

    int dL[8] = { -1,-1,-1, 0,0, 1,1,1 };
    int dC[8] = { -1, 0, 1,-1,1,-1,0,1 };

    for (int k = 0; k < 8; k++) {
        int nl = L + dL[k];
        int nc = C + dC[k];

        if (nl < 0 || nl >= jardim.getLinhas() || nc < 0 || nc >= jardim.getColunas())
            continue;

        Solo& sViz = jardim.getSolo(nl, nc);
        Planta* pViz = sViz.getPlanta();

        if (pViz != nullptr) {
            instantesSemVizinhos = 0;
            char ch = (char)std::tolower((unsigned char)pViz->getChar());
            if (ch == 'r' || ch == 'c' || ch == 'e' || ch == 'x')
                modo = ch;
            else
                modo = 'x';
            break;
        }
    }

    return nullptr; // Exótica não multiplica
}

void Exotica::mostrarInfoPlanta() const {
    Planta::mostrarInfoPlanta();
    std::cout << "Tipo: Exotica (Camaleao) | modo=" << modo
              << " | semVizinhos=" << instantesSemVizinhos << "\n";
}
