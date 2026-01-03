#include "Comando.h"
#include "Jardim.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <fstream>
#include "Ferramentas/Regador.h"
#include "Ferramentas/PacoteAdubo.h"
#include "Ferramentas/TesouraPoda.h"
#include "Ferramentas/FerramentaZ.h"

#include "Solo.h"

using namespace std;

// -------- Helpers de parsing/validação --------
static bool temExtra(std::istringstream& iss) {
    std::string lixo;
    if (iss >> lixo)
        return true;   // ainda havia tokens
    return false;      // não havia mais nada
}

static bool leInt(std::istringstream& iss, int& out) {
    std::string tok;
    if (!(iss >> tok)) return false;

    std::istringstream tmp(tok);
    int v;
    char extra;
    if (!(tmp >> v)) return false;
    if (tmp >> extra) return false; // ex: "12a"
    out = v;
    return true;
}

static bool leChar(std::istringstream& iss, char& out) {
    std::string tok;
    if (!(iss >> tok)) return false;
    if (tok.size() != 1) return false;
    out = tok[0];
    return true;
}

// posição no formato "df" (2 letras juntas)
static bool lePos(std::istringstream& iss, char& l, char& c) {
    std::string pos;
    if (!(iss >> pos)) return false;
    if (pos.size() != 2) return false;
    l = pos[0];
    c = pos[1];
    return true;
}

static bool eLetraPos(char x) {
    x = (char)std::tolower((unsigned char)x);
    return x >= 'a' && x <= 'z';
}

static bool eTipoPlanta(char t) {
    t = (char)std::tolower((unsigned char)t);
    return t == 'c' || t == 'r' || t == 'e' || t == 'x';
}

static bool eTipoFerramenta(char t) {
    t = (char)std::tolower((unsigned char)t);
    return t == 'g' || t == 'a' || t == 't' || t == 'z';
}

// -------- Classe Comando --------
Comando::Comando() : jardim(nullptr), jardimCriado(false) {
}

Comando::~Comando() {
    delete jardim;
    jardim = nullptr;
}

std::string Comando::obtemInput(std::string message) {
    std::string input;
    std::cout << message << "\n> ";
    std::getline(std::cin, input);
    return input;
}

void Comando::mostraAjuda() const {
    std::cout << "\n==========================/LISTA DE COMANDOS/==========================================\n";
    std::cout << "-avanca [n]        -lplantas     -colhe <l><c>             -grava <nome>\n";
    std::cout << "-entra <l><c>      -lplanta      -planta <l><c> <tipo>     -recupera <nome>\n";
    std::cout << "-sai               -larea        -larga                    -apaga <nome>\n";
    std::cout << "                   -lsolo        -pega <n>                 -executa <nome-do-ficheiro>\n";
    std::cout << "                   -lferr        -compra <n>               -fim\n";
    std::cout << "======================================================================================\n";
}

// LOOP PRINCIPAL (Lê apenas o teclado)
bool Comando::executa() {
    mostraAjuda();

    while (true) {
        std::string linha = obtemInput("Comando:");

        // Se processaLinha devolver false (porque escreveste 'fim'), o programa fecha
        if (!processaLinha(linha)) {
            return false;
        }
    }
}

bool Comando::processaLinha(std::string linha) {
    if (linha.empty() || linha[0] == '#') return true;

    std::istringstream iss(linha);
    std::string cmd;
    if (!(iss >> cmd)) return true;

    // antes do jardim existir, só aceitamos: jardim, executa, fim
    if (!jardimCriado && cmd != "jardim" && cmd != "executa" && cmd != "fim") {
        std::cout << "Tem de criar o jardim primeiro com: jardim <linhas> <colunas>\n";
        return true;
    }

    // -------------------- jardim <n> <n> --------------------

    if (cmd == "jardim") {
        int lin, col;
        if (!leInt(iss, lin) || !leInt(iss, col) || temExtra(iss)) {
            std::cout << "Sintaxe: jardim <linhas> <colunas>\n";
            return true;
        }
        if (jardimCriado) {
            std::cout << "O comando 'jardim' so pode ser usado uma vez.\n";
            return true;
        }
        if (lin <= 0 || col <= 0) {
            std::cout << "Linhas e colunas tem de ser > 0.\n";
            return true;
        }
        if (lin > 26 || col > 26) {
            std::cout << "Maximo permitido -> 26x26.\n";
            return true;
        }

        jardim = new Jardim(lin, col);
        jardimCriado = true;
        std::cout << "Jardim criado (" << lin << "x" << col << ").\n";
        jardim->mostra();
        return true;
    }

    // -------------------- fim --------------------
    if (cmd == "fim") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: fim (sem parametros)\n";
            return true;
        }
        std::cout << "Fim do programa\n\n"
                  << "Trabalho Feito por:\n"
                  << "  Bruna Alves de Sousa   No 2022139713\n"
                  << "  Ricardo Antonio Ribeiro Miguel   No 2022135245\n";
        return false;
    }
    // -------------------- avanca [n] --------------------
    if (cmd == "avanca") {
        int n = 1;
        int tmp;

        if (leInt(iss, tmp)) n = tmp;
        if (temExtra(iss)) {
            std::cout << "Sintaxe: avanca [n]\n";
            return true;
        }
        if (n <= 0) {
            std::cout << "'n' tem de ser inteiro positivo.\n";
            return true;
        }
        jardim->avanca(n);
        jardim->mostra();

        return true;
    }

    // -------------------- listagens sem args --------------------
    if (cmd == "lplantas" || cmd == "larea") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: " << cmd << " (sem parametros)\n";
            return true;
        }

        if (cmd == "lplantas") {
            jardim->listaPlantas();
        } else { // larea
            jardim->listaArea();
        }

        return true;
    }


    // -------------------- lferr --------------------
    if (cmd == "lferr") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: lferr\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }

        jardim->getJardineiro()->listarFerramentas();
        return true;
    }

    // -------------------- lplanta <lc> --------------------
    if (cmd == "lplanta") {
        char l, c;
        if (!lePos(iss, l, c) || temExtra(iss)) {
            std::cout << "Sintaxe: lplanta <lc>  (ex: lplanta df)\n";
            return true;
        }
        if (!eLetraPos(l) || !eLetraPos(c)) {
            std::cout << "Posicao invalida. Usa duas letras (a..z)\n";
            return true;
        }

        int li = std::tolower((unsigned char)l) - 'a';
        int co = std::tolower((unsigned char)c) - 'a';

        if (li < 0 || li >= jardim->getLinhas() || co < 0 || co >= jardim->getColunas()) {
            std::cout << "Posicao fora do jardim.\n";
            return true;
        }

        const Solo& s = jardim->getSolo(li, co);
        std::cout << "Planta em " << (char)std::toupper(l) << (char)std::toupper(c) << ":\n";
        s.mostraPlanta();
        return true;
    }


    // -------------------- lsolo <lc> [n] --------------------
    if (cmd == "lsolo") {
        char l, c;
        if (!lePos(iss, l, c)) {
            std::cout << "Sintaxe: lsolo <lc> [n]  (ex: lsolo df 2)\n";
            return true;
        }
        if (!eLetraPos(l) || !eLetraPos(c)) {
            std::cout << "Posicao invalida. Use duas letras (a..z)\n";
            return true;
        }

        int n = 0;
        int tmp;
        if (leInt(iss, tmp)) n = tmp;

        if (temExtra(iss)) {
            std::cout << "Sintaxe: lsolo <lc> [n]\n";
            return true;
        }
        if (n < 0) {
            std::cout << "'n' tem de ser >= 0.\n";
            return true;
        }

        int li = std::tolower((unsigned char)l) - 'a';
        int co = std::tolower((unsigned char)c) - 'a';

        if (li < 0 || li >= jardim->getLinhas() || co < 0 || co >= jardim->getColunas()) {
            std::cout << "Posicao fora do jardim.\n";
            return true;
        }

        // n == 0: só a posição
        if (n == 0) {
            const Solo& s = jardim->getSolo(li, co);
            std::cout << "Solo em " << (char)std::toupper(l) << (char)std::toupper(c) << ":\n";
            s.mostraSolo();
            return true;
        }

        // n > 0: mostra área (2n+1)x(2n+1)
        std::cout << "Solo num raio " << n << " em torno de "
                  << (char)std::toupper(l) << (char)std::toupper(c) << ":\n";

        for (int i = li - n; i <= li + n; i++) {
            for (int j = co - n; j <= co + n; j++) {
                if (i < 0 || j < 0 || i >= jardim->getLinhas() || j >= jardim->getColunas())
                    continue;

                std::cout << "\n[" << (char)('A' + i) << (char)('A' + j) << "]\n";
                jardim->getSolo(i, j).mostraSolo();
            }
        }
        return true;
    }


    // -------------------- colhe <lc> --------------------
    if (cmd == "colhe") {
        char l, c;
        if (!lePos(iss, l, c) || temExtra(iss)) {
            std::cout << "Sintaxe: colhe <lc> (ex: colhe fb)\n";
            return true;
        }
        if (!eLetraPos(l) || !eLetraPos(c)) {
            std::cout << "Posicao invalida. Use duas letras (a..z)\n";
            return true;
        }

        bool ok = jardim->colhe(l, c);
        if (ok) jardim->mostra();
        return true;
    }


    // -------------------- planta <lc> <tipo> --------------------
    if (cmd == "planta") {
        char l, c;
        char tipo;
        if (!lePos(iss, l, c) || !leChar(iss, tipo) || temExtra(iss)) {
            std::cout << "Sintaxe: planta <lc> <tipo> (tipo: c | r | e | x)\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }
        if (!eLetraPos(l) || !eLetraPos(c)) {
            std::cout << "Posicao invalida. Use duas letras (a..z).\n";
            return true;
        }
        if (!eTipoPlanta(tipo)) {
            std::cout << "Tipo invalido. Use: c r e x\n";
            return true;
        }
        std::cout << "Comando valido: planta " << l << c << " " << (char)std::tolower(tipo) << "\n";
        jardim->planta(l, c, tipo);
        jardim->mostra();

        return true;
    }

    // -------------------- larga --------------------
    if (cmd == "larga") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: larga\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }

        Jardineiro* j = jardim->getJardineiro();
        if (!j->temFerramenta()) {
            std::cout << "Nao tens ferramenta na mao.\n";
            return true;
        }

        Ferramenta* f = j->largaFerramenta();  // tira da mão
        j->adicionaAoInventario(f);            // continua na posse (mochila)

        std::cout << "Guardaste '" << f->getNome() << "' no inventario.\n";
        jardim->mostra();
        return true;
    }


    // -------------------- pega <n> --------------------
    if (cmd == "pega") {
        int n;
        if (!leInt(iss, n) || temExtra(iss)) {
            std::cout << "Sintaxe: pega <n>\n";
            return true;
        }
        if (n <= 0) {
            std::cout << "'n' tem de ser > 0.\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }

        Jardineiro* j = jardim->getJardineiro();

        if (!j->equipaDoInventario(n)) {
            std::cout << "ERRO: Nao existe ferramenta " << n << " no inventario.\n";
            return true;
        }

        std::cout << "Ferramenta " << n << " equipada na MAO.\n";
        jardim->mostra();
        return true;
    }



    // -------------------- compra <c> --------------------
    if (cmd == "compra") {
        char t;
        if (!leChar(iss, t) || temExtra(iss)) {
            std::cout << "Sintaxe: compra <c> (c: g | a | t | z)\n";
            return true;
        }
        if (!eTipoFerramenta(t)) {
            std::cout << "Tipo invalido. Use: g | a | t | z\n";
            return true;
        }

        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }

        Jardineiro* j = jardim->getJardineiro();

        Ferramenta* nova = nullptr;

        switch (std::tolower((unsigned char)t)) {
            case 'g': nova = new Regador(); break;
            case 'a': nova = new PacoteAdubo(); break;
            case 't': nova = new TesouraPoda(); break;
            case 'z': nova = new FerramentaZ(); break;
            default: break;
        }

        if (!nova) {
            std::cout << "ERRO: nao foi possivel criar a ferramenta.\n";
            return true;
        }

        if (!j->temFerramenta()) {
            j->pegaFerramenta(nova);
            std::cout << "Compraste '" << nova->getNome() << "' e equipaste na MAO.\n";
        } else {
            j->adicionaAoInventario(nova);
            std::cout << "Compraste '" << nova->getNome() << "' e guardaste no INV.\n";
        }

        jardim->mostra();
        return true;
    }


    // -------------------- entra <lc> --------------------
    if (cmd == "entra") {
        char l, c;
        if (!lePos(iss, l, c) || temExtra(iss)) {
            std::cout << "Sintaxe: entra <lc> (ex: entra fg)\n";
            return true;
        }
        if (!eLetraPos(l) || !eLetraPos(c)) {
            std::cout << "Posição invalida. Use duas letras (a..z)\n";
            return true;
        }
        if (!jardim->entraJardineiro(l, c)) {
            std::cout << "ERRO: posicao fora do jardim.\n";
            return true;
        }

        jardim->mostra();
        return true;
    }

    // -------------------- sai --------------------
    if (cmd == "sai") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: sai (sem parametros)\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "O jardineiro ja esta fora.\n";
            return true;
        }
        jardim->saiJardineiro();
        jardim->mostra();
        return true;
    }

    // -------------------- movimentos e/d/c/b --------------------
    if (cmd == "e" || cmd == "d" || cmd == "c" || cmd == "b") {
        if (!jardim->podeMover()) {
            std::cout << "ERRO: Ja fizeste " << Settings::Jardineiro::max_movimentos
                      << " movimentos neste turno. Usa: avanca\n";
            return true;
        }

        if (temExtra(iss)) {
            std::cout << "Sintaxe: " << cmd << " (sem parametros)\n";
            return true;
        }
        if (!jardim->temJardineiro()) {
            std::cout << "ERRO: O jardineiro ainda nao entrou. Use: entra <lc>\n";
            return true;
        }

        char dir = cmd[0]; // e d c b
        // define o teu mapeamento (exemplo):
        // e = esquerda, d = direita, c = cima, b = baixo
        char real;
        if (dir == 'e') real = 'o';       // oeste
        else if (dir == 'd') real = 'e';  // este
        else if (dir == 'c') real = 'n';  // norte
        else real = 's';                  // sul

        bool ok = jardim->getJardineiro()->mover(real, jardim->getLinhas(), jardim->getColunas());
        if (!ok) {
            std::cout << "Nao pode sair do jardim.\n";
        } else {
            jardim->registaMovimento();  // ✅ conta movimento válido
            jardim->apanhaFerramentaSeExistir();
        }

        jardim->mostra();
        return true;
    }


    // -------------------- executa <ficheiro> --------------------
    if (cmd == "executa") {
        std::string fich;
        if (!(iss >> fich) || temExtra(iss)) {
            std::cout << "Sintaxe: executa <nome-do-ficheiro>\n";
            return true;
        }

        std::ifstream ficheiro(fich);
        if (!ficheiro.is_open()) {
            std::cout << "Erro: Nao foi possivel abrir o ficheiro '" << fich << "'\n";
            return true;
        }

        std::string linhaFich;
        while (std::getline(ficheiro, linhaFich)) {
            // Ignora linhas vazias ou comentários
            if (linhaFich.empty() || linhaFich[0] == '#') continue;

            std::cout << "A executar do ficheiro: " << linhaFich << "\n";
            // processaLinha(linhaFich);
        }
        ficheiro.close();
        return true;
    }

    // -------------------- grava <nome> --------------------
    if (cmd == "grava") {
        string nome;
        if (!(iss >> nome) || temExtra(iss)) {
            cout << "Sintaxe: grava <nome>" << endl;
        } else {
            // Se já existir um save com este nome, apaga o antigo antes de substituir
            if (saves.count(nome)) {
                delete saves[nome];
            }
            // Cria uma cópia profunda do jardim atual
            saves[nome] = new Jardim(*jardim);
            cout << "Jardim guardado com sucesso: " << nome << endl;
        }
        return true;
    }

    // -------------------- recupera <nome> --------------------
    if (cmd == "recupera") {
        string nome;
        if (!(iss >> nome) || temExtra(iss)) {
            cout << "Sintaxe: recupera <nome>" << endl;
        } else {
            auto it = saves.find(nome);
            if (it == saves.end()) {
                cout << "Erro: Save '" << nome << "' nao encontrado." << endl;
            } else {
                // 1. Apaga o jardim que está a correr agora
                delete jardim;
                // 2. Substitui pelo jardim que estava guardado
                jardim = it->second;
                // 3. Remove a entrada do mapa (a cópia é eliminada dos saves)
                saves.erase(it);
                cout << "Jardim recuperado. Copia eliminada dos saves." << endl;
                jardim->mostra();
            }
        }
        return true;
    }

    // -------------------- apaga <nome> --------------------
    if (cmd == "apaga") {
        string nome;
        if (!(iss >> nome) || temExtra(iss)) {
            cout << "Sintaxe: apaga <nome>" << endl;
        } else {
            auto it = saves.find(nome);
            if (it != saves.end()) {
                delete it->second; // Limpa a memória da cópia
                saves.erase(it);   // Remove do mapa
                cout << "Save '" << nome << "' apagado." << endl;
            } else {
                cout << "Erro: Save nao encontrado." << endl;
            }
        }
        return true;
    }

    // se chegou aqui, não existe
    std::cout << "Comando invalido! Use um da lista.\n";
    return true;

}