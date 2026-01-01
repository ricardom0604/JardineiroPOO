
// Comando.cpp (versão focada em VALIDAÇÃO de comandos - Meta 1)
// - Valida sintaxe, tipos, número de argumentos e "args a mais".
// - Assume posições no formato "df" (2 letras juntas), como no enunciado.
// - Impõe: antes de criar jardim, só aceita "jardim", "executa" e "fim".
// - Aqui "jardim" cria mesmo o Jardim (para poderes avançar já).
//   Se preferires só validar sem criar, diz e eu adapto.

#include "Comando.h"
#include "Jardim.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

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
    std::cout << "-avanca [n]        -lplantas     -colhe <l> <c>            -grava <nome>\n";
    std::cout << "-entra <l> <c>     -lplanta      -planta <l> <c> <tipo>    -recupera <nome>\n";
    std::cout << "-sai               -larea        -larga                    -apaga <nome>\n";
    std::cout << "                   -lsolo        -pega <n>                 -executa <nome-do-ficheiro>\n";
    std::cout << "                   -lferr        -compra <n>               -fim\n";
    std::cout << "======================================================================================\n";
}

bool Comando::executa() {
    mostraAjuda();

    std::string linha = obtemInput("Comando:");
    std::istringstream iss(linha);

    std::string cmd;
    if (!(iss >> cmd)) {
        std::cout << "Comando vazio.\n";
        return true;
    }

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
        std::cout << "Comando valido: avanca " << n << "\n";
        return true;
    }

    // -------------------- listagens sem args --------------------
    if (cmd == "lplantas" || cmd == "larea" || cmd == "lferr") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: " << cmd << " (sem parametros)\n";
            return true;
        }
        std::cout << "Comando valido: " << cmd << "\n";
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
        std::cout << "Comando valido: lplanta " << l << c << "\n";
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

        int n;
        if (leInt(iss, n)) {
            if (temExtra(iss)) {
                std::cout << "Sintaxe: lsolo <lc> [n]\n";
                return true;
            }
            if (n < 0) {
                std::cout << "'n' tem de ser >= 0.\n";
                return true;
            }
            std::cout << "Comando valido: lsolo " << l << c << " " << n << "\n";
        } else {
            if (temExtra(iss)) {
                std::cout << "Sintaxe: lsolo <lc> [n]\n";
                return true;
            }
            std::cout << "Comando valido: lsolo " << l << c << "\n";
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
        std::cout << "Comando valido: colhe " << l << c << "\n";
        return true;
    }

    // -------------------- planta <lc> <tipo> --------------------
    if (cmd == "planta") {
        char l, c;
        char tipo;
        if (!lePos(iss, l, c) || !leChar(iss, tipo) || temExtra(iss)) {
            std::cout << "Sintaxe: planta <lc> <tipo> (tipo: c r e x)\n";
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
        return true;
    }

    // -------------------- larga --------------------
    if (cmd == "larga") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: larga (sem parametros)\n";
            return true;
        }
        std::cout << "Comando valido: larga\n";
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
        std::cout << "Comando valido: pega " << n << "\n";
        return true;
    }

    // -------------------- compra <c> --------------------
    if (cmd == "compra") {
        char t;
        if (!leChar(iss, t) || temExtra(iss)) {
            std::cout << "Sintaxe: compra <c> (c: g a t z)\n";
            return true;
        }
        if (!eTipoFerramenta(t)) {
            std::cout << "Tipo invalido. Use: g a t z\n";
            return true;
        }
        std::cout << "Comando valido: compra " << (char)std::tolower(t) << "\n";
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
        std::cout << "Comando valido: sai\n";
        return true;
    }

    // -------------------- movimentos e/d/c/b --------------------
    if (cmd == "e" || cmd == "d" || cmd == "c" || cmd == "b") {
        if (temExtra(iss)) {
            std::cout << "Sintaxe: " << cmd << " (sem parametros)\n";
            return true;
        }
        std::cout << "Comando valido: mover " << cmd << "\n";
        return true;
    }

    // -------------------- grava/recupera/apaga <nome> --------------------
    if (cmd == "grava" || cmd == "recupera" || cmd == "apaga") {
        std::string nome;
        if (!(iss >> nome) || temExtra(iss)) {
            std::cout << "Sintaxe: " << cmd << " <nome>\n";
            return true;
        }
        std::cout << "Comando valido: " << cmd << " " << nome << "\n";
        return true;
    }

    // -------------------- executa <ficheiro> --------------------
    if (cmd == "executa") {
        std::string fich;
        if (!(iss >> fich) || temExtra(iss)) {
            std::cout << "Sintaxe: executa <nome-do-ficheiro>\n";
            return true;
        }
        std::cout << "Comando valido: executa " << fich << "\n";
        return true;
    }

    // se chegou aqui, não existe
    std::cout << "Comando invalido! Use um da lista.\n";
    return true;
}
