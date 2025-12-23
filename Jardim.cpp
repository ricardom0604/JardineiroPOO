#include "Jardim.h"
#include "Roseira.h"
#include "Solo.h"
#include "posicao.h"

bool Solo::eValido(char l, char c) {
    return std::tolower(l) >= 'a' && std::tolower(l) <= 'a'  && std::tolower(c) >= 'a' && std::tolower(c) <= 'z';
}

//Construtor
Jardim::Jardim(int l, int c) : l(l), c(c) {
    mapa = new Solo*[l];  //cria um vetor de l ponteiro um para cada linha
    for (int i = 0; i < l; i++) {
        mapa[i] = new Solo[c]; //para cada linha cria um array de char
        for (int j = 0; j < c; j++) {
            mapa[i][j] = Solo(Posicao(i, j));
        }
    }
    numPlantas = 0;
    numFerramentas = 0;
    plantas = new Planta*[numPlantas];
    ferramentas = new Ferramenta*[numFerramentas];
}

//Destrutor
Jardim::~Jardim() {
    // Destruir as plantas
    for (int i = 0; i < numPlantas; i++)
        delete plantas[i];
    // Destruir os arrays de Solo e Ferramentas
    for (int i = 0; i < l; i++) {
        delete[] mapa[i];
    }
    delete[] mapa;
    delete []ferramentas;
    delete []plantas;
}

void Jardim::mostra() {
    printf("   ");
    for (int i = 0; i < c; i++)
        printf(" %c ", ('A' + i));
    printf("\n  ");
    for (int i = 0; i < c; i++)
        printf("---");
    printf("--\n");

    for (int i = 0; i < l; i++) {
        printf("%c |", ('A' + i));
        for (int j = 0; j < c; j++) {
            char c = mapa[i][j].getPlanta()->getChar();
            printf(" %c ", c);
        }
        printf("|\n");
    }

    printf("  -");
    for (int i = 0; i < c; i++)
        printf("---");
    printf("-\n");
}

void Jardim::mostraPlantas() const {
    for (int i = 0; i < numPlantas; i++)
        plantas[i]->mostrarInfoPlanta();
}

//Função de criar planta
void Jardim::planta(char l, char c, char tipo){
    int linha = l - 'A';
    int coluna = c - 'A';

    Planta *p = nullptr;
    if (mapa[linha][coluna].getPlanta() != nullptr) {
        std::cout << "ERRO: Posicao já ocupada.\n";
        return;
    }
    switch (tipo) {
        case 'r':
            p = new Roseira();
        break;
        // Adicionar outros tipos de plantas aqui (c, e, x)

        default:
            std::cout << "ERRO: Tipo de planta desconhecido.\n";
        return;
    }
    if (p != nullptr) {
        mapa[linha][coluna].setPlanta(p);
    }
    mapa[linha][coluna].setPlanta(p);
}


bool Jardim::encontraVizinho(const Posicao& minhaPosicao, Posicao& destino) const {
    int linha = minhaPosicao.getL();
    int coluna = minhaPosicao.getC();

    // deslocamentos para as 8 posições vizinhas
    int dL[8] = { -1, -1, -1,  0, 0, 1, 1, 1 };
    int dC[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) {
        int novaL = linha + dL[i];
        int novaC = coluna + dC[i];

        // verificar se está dentro dos limites do jardim
        if (novaL >= 0 && novaL < l && novaC >= 0 && novaC < c) {

            // verificar se a posição está vazia
            if (!mapa[novaL][novaC].temPlanta()) {
                destino.setL(novaL);
                destino.setC(novaC);
                return true;
            }
        }
    }
    return false;  //n foi encontrado nehum vizinho
}
