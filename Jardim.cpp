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
#include "Plantas/Cacto.h"
#include "Plantas/ErvaDaninha.h"
#include "Regador.h"
#include "PacoteAdubo.h"
#include "TesouraPoda.h"
#include "FerramentaZ.h"
#include <vector>

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

    apanhaFerramentaSeExistir();

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
                    printf(" * ");
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

    // Informação extra do jardineiro (opcional)
    if (jardineiro != nullptr && jardineiro->temFerramenta()) {
        std::cout << "Ferramenta na mao: "
                  << jardineiro->getFerramenta()->getNome()
                  << "\n";
    }
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
        case 'r': p = new Roseira(); break;
        case 'c': p = new Cacto(); break;
        case 'e': p = new ErvaDaninha(); break;
        case 'x': p = new Exotica(); break;
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

void Jardim::apanhaFerramentaSeExistir() {
    if (!jardineiro) return;

    Posicao pj = jardineiro->getPosicao();
    Solo& s = getSolo(pj);

    if (!s.temFerramenta()) return;

    // 1) apanha a ferramenta do chão
    Ferramenta* f = s.removeFerramenta();

    // 2) põe na mão se estiver vazia, senão vai para inventário
    if (!jardineiro->temFerramenta()) {
        jardineiro->pegaFerramenta(f);
        std::cout << "Apanhaste e equipaste '" << f->getNome() << "' (MAO).\n";
    } else {
        jardineiro->adicionaAoInventario(f);
        std::cout << "Apanhaste '" << f->getNome() << "' (INV).\n";
    }

    // 3) “por magia” nasce outra aleatória em posição aleatória
    colocarFerramentaAleatoria();
}


Solo& Jardim::getSolo(int linha, int coluna) {
    return mapa[linha][coluna];
}

const Solo& Jardim::getSolo(int linha, int coluna) const {
    return mapa[linha][coluna];
}

Solo& Jardim::getSolo(const Posicao& p) {
    return mapa[p.getL()][p.getC()];
}

const Solo& Jardim::getSolo(const Posicao& p) const {
    return mapa[p.getL()][p.getC()];
}

void Jardim::saiJardineiro() {
    delete jardineiro;
    jardineiro = nullptr;
}

void Jardim::avanca(int n) {
    if (n <= 0) return;

    for (int passo = 0; passo < n; passo++) {
        //std::cout << "\n--- Instante " << passo + 1 << " ---\n"; (so p ver se o avanca ta bom)

        // Guardar nascimentos (para não mexer na matriz enquanto percorremos)
        struct Nascimento {
            int l, c;
            Planta* p;
        };
        std::vector<Nascimento> nascimentos;

        // 0) ferramenta ativa atua 1x por instante
        if (jardineiro && jardineiro->temFerramenta()) {
            Solo& sJ = getSolo(jardineiro->getPosicao());
            Ferramenta* f = jardineiro->getFerramenta();

            f->usar(sJ, *jardineiro);

            if (f->estaGasta()) {
                Ferramenta* gasta = jardineiro->largaFerramenta();
                delete gasta; // some
            }
        }

        // 1) cada instante: cada planta faz a sua ação
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                Solo& s = mapa[i][j];
                Planta* p = s.getPlanta();

                if (!p) continue;

                // A planta atua sobre o solo
                p->cadaInstante(s);

                // Exótica camaleão: usa isto para "ver vizinhos" e atualizar modo
                // (ela devolve nullptr, mas faz update interno)

                // Morte
                if (p->verificaMorte(s)) {
                    p->acaoMorte(s);
                    Planta* morto = s.removePlanta();
                    delete morto;
                    continue;
                }

                // Multiplicação (se alguma planta devolver nova planta)
                Planta* nova = p->tentaMultiplicar(*this, Posicao(i, j));
                if (nova != nullptr) {
                    Posicao destino;
                    if (encontraVizinho(Posicao(i, j), destino)) {
                        nascimentos.push_back({ destino.getL(), destino.getC(), nova });
                    } else {
                        delete nova; // não há espaço
                    }
                }
            }
        }

        // 2) Colocar os nascimentos no fim do instante
        for (auto& nasc : nascimentos) {
            if (!mapa[nasc.l][nasc.c].temPlanta()) {
                mapa[nasc.l][nasc.c].setPlanta(nasc.p);
            } else {
                delete nasc.p; // se entretanto ocupou, limpa
            }
        }
    }
}

bool Jardim::colhe(char lChar, char cChar) {
    int linha  = std::tolower((unsigned char)lChar) - 'a';
    int coluna = std::tolower((unsigned char)cChar) - 'a';

    if (linha < 0 || linha >= l || coluna < 0 || coluna >= c) {
        std::cout << "ERRO: Coordenadas fora do jardim.\n";
        return false;
    }

    Solo& s = mapa[linha][coluna];

    if (!s.temPlanta()) {
        std::cout << "ERRO: Nao existe planta nessa posicao.\n";
        return false;
    }

    Planta* p = s.removePlanta();   // tira do solo
    delete p;                       // apaga a planta (colhida)

    std::cout << "Planta colhida em " << (char)std::toupper(lChar)
              << (char)std::toupper(cChar) << ".\n";
    return true;
}

bool Jardim::compra(char tipo) {
    if (!jardineiro) {
        std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
        return false;
    }

    tipo = (char)std::tolower((unsigned char)tipo);

    Ferramenta* nova = nullptr;
    switch (tipo) {
        case 'g': nova = new Regador(); break;
        case 'a': nova = new PacoteAdubo(); break;
        case 't': nova = new TesouraPoda(); break;
        case 'z': nova = new FerramentaZ(); break;
        default:
            std::cout << "ERRO: Tipo invalido. Use: g a t z\n";
            return false;
    }

    // posição atual do jardineiro
    Posicao pj = jardineiro->getPosicao();
    Solo& s = getSolo(pj);

    // regra: compra coloca no chão; se já houver ferramenta ali, dá erro
    if (s.temFerramenta()) {
        std::cout << "ERRO: Ja existe uma ferramenta no chao nesta posicao.\n";
        delete nova;
        return false;
    }

    s.setFerramenta(nova);
    std::cout << "Comprou '" << nova->getNome() << "' e ficou no chao.\n";
    return true;
}

void Jardim::listaPlantas() const {
    bool encontrou = false;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            Solo& s = mapa[i][j];
            Planta* p = s.getPlanta();
            if (!p) continue;

            encontrou = true;
            std::cout << "[" << (char)('A' + i) << (char)('A' + j) << "]\n";
            p->mostrarInfoPlanta();
            std::cout << "\n";
        }
    }

    if (!encontrou) {
        std::cout << "Nao existem plantas no jardim.\n";
    }
}

void Jardim::listaArea() const {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            const Solo& s = mapa[i][j];
            std::cout << "=== [" << (char)('A' + i) << (char)('A' + j) << "] ===\n";
            s.mostraSolo();
            std::cout << "\n";
        }
    }
}