#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include "Jardim.h"
#include "Solo.h"
#include "Posicao.h"
#include "Ferramenta.h"
#include "Plantas/Planta.h"
#include "Plantas/Roseira.h"
#include "Plantas/Exotica.h"
#include "Regador.h"
#include "PacoteAdubo.h"
#include "TesouraPoda.h"
#include "FerramentaZ.h"

Jardim::Jardim(int l, int c) : l(l), c(c) {
    srand(static_cast<unsigned int>(time(NULL)));

    // Alocação do mapa de Solo
    mapa = new Solo*[l];
    for (int i = 0; i < l; i++) {
        mapa[i] = new Solo[c];
        for (int j = 0; j < c; j++) {
            mapa[i][j] = Solo(Posicao(i, j));
        }
    }

    // Inicialização de contadores
    numPlantas = 0;
    numFerramentas = 0;

    // Inicializar vetores dinâmicos auxiliares como vazios
    plantas = nullptr;
    ferramentas = nullptr;
    jardineiro = nullptr;

    // Colocar as 3 ferramentas iniciais conforme o enunciado
    for(int i = 0; i < 3; i++) {
        colocarFerramentaAleatoria();
    }
}

Jardim::~Jardim() {
    // Libertar a memória de cada célula do Solo
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            // O Solo é dono da planta e da ferramenta
            delete mapa[i][j].getPlanta();
            delete mapa[i][j].getFerramenta();
        }
        delete[] mapa[i];
    }
    delete[] mapa;

    // Estes vetores devem ser geridos com cuidado se guardarem cópias de ponteiros
    delete[] ferramentas;
    delete[] plantas;
    delete jardineiro;

}

void Jardim::colocarFerramentaAleatoria() {
    Ferramenta* f = nullptr;
    int tipo = rand() % 4;

    switch (tipo) {
        case 0: f = new Regador(); break;
        case 1: f = new PacoteAdubo(); break;
        case 2: f = new TesouraPoda(); break;
        case 3: f = new FerramentaZ(); break;
    }

    if (!f) return;

    bool colocado = false;
    int tentativas = 0;
    // Tenta encontrar uma posição vazia (limite de tentativas para evitar loop infinito)
    while (!colocado && tentativas < (l * c)) {
        int linhaRand = rand() % l;
        int colunaRand = rand() % c;

        if (mapa[linhaRand][colunaRand].getFerramenta() == nullptr) {
            mapa[linhaRand][colunaRand].setFerramenta(f);
            colocado = true;
        }
        tentativas++;
    }

    if (!colocado) delete f; // Limpeza se não conseguir colocar
}

bool Jardim::entraJardineiro(char lChar, char cChar) {
    int linha  = std::tolower((unsigned char)lChar) - 'a';
    int coluna = std::tolower((unsigned char)cChar) - 'a';

    if (linha < 0 || linha >= l || coluna < 0 || coluna >= c)
        return false;

    if (!jardineiro)
        jardineiro = new Jardineiro(linha, coluna);
    else
        jardineiro->setPosicao(linha, coluna);

    return true;
}


void Jardim::mostra() {
    // Régua superior (Letras A B C...)
    printf("    "); // 4 espaços para alinhar com a margem lateral "A |"
    for (int j = 0; j < c; j++)
        printf(" %c ", ('A' + j));
    printf("\n");

    // Moldura superior
    printf("   +");
    for (int j = 0; j < c; j++)
        printf("---");
    printf("+\n"); // O + fecha o canto superior direito

    // Conteúdo do Jardim
    for (int i = 0; i < l; i++) {
        // Régua lateral esquerda
        printf(" %c |", ('A' + i));

        for (int j = 0; j < c; j++) {
            if (jardineiro != nullptr) {
                Posicao pj = jardineiro->getPosicao();
                if (pj.getL() == i && pj.getC() == j) {
                    printf(" J ");
                    continue;   // salta plantas/ferramentas
                }
            }
            char visual = ' '; // Espaço por defeito

            // Verificação de ocupação
            Planta* p = mapa[i][j].getPlanta();
            Ferramenta* f = mapa[i][j].getFerramenta();

            if (p != nullptr) {
                visual = p->getChar(); // Mostra a planta
            }
            else if (f != nullptr) {
                visual = f->getChar(); // Mostra a ferramenta se não houver planta
            }

            printf(" %c ", visual);
        }

        // Moldura lateral direita
        printf("|\n");
    }
    // Moldura inferior
    printf("   +");
    for (int j = 0; j < c; j++)
        printf("---");
    printf("+\n");
}

void Jardim::planta(char lChar, char cChar, char tipo) {
    // Converter para minúsculas para aceitar comandos 'A' ou 'a'
    int linha = std::tolower(lChar) - 'a';
    int coluna = std::tolower(cChar) - 'a';

    // Verificação de limites
    if (linha < 0 || linha >= l || coluna < 0 || coluna >= c) {
        std::cout << "ERRO: Coordenadas invalidas.\n";
        return;
    }

    if (mapa[linha][coluna].temPlanta()) {
        std::cout << "ERRO: Posicao ocupada por outra planta.\n";
        return;
    }

    Planta *p = nullptr;
    switch (std::tolower(tipo)) {
        case 'x': p = new Exotica(); break;
        case 'r': p = new Roseira(); break;
        // Futuro: case 'c': case 'e': case 'x'
        default:
            std::cout << "ERRO: Tipo de planta desconhecido.\n";
            return;
    }

    if (p != nullptr) {
        mapa[linha][coluna].setPlanta(p);
        std::cout << "Planta colocada com sucesso em " << lChar << cChar << ".\n";
    }
}

bool Jardim::encontraVizinho(const Posicao& minhaPosicao, Posicao& destino) const {
    int linha = minhaPosicao.getL();
    int coluna = minhaPosicao.getC();

    int dL[8] = { -1, -1, -1,  0, 0, 1, 1, 1 };
    int dC[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) {
        int novaL = linha + dL[i];
        int novaC = coluna + dC[i];

        if (novaL >= 0 && novaL < l && novaC >= 0 && novaC < c) {
            if (!mapa[novaL][novaC].temPlanta()) {
                destino.setL(novaL);
                destino.setC(novaC);
                return true;
            }
        }
    }
    return false;
}

Solo& Jardim::getSolo(int linha, int coluna) {
    return mapa[linha][coluna];
}

const Solo& Jardim::getSolo(int linha, int coluna) const {
    return mapa[linha][coluna];
}