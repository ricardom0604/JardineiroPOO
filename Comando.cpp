#include "Comando.h"

#include "Solo.h"


using namespace std;

Comando::Comando() {
    std::string input;
    bool valido = false;
    int l, c;

    while (!valido) {
        std::cout << "Introduza o tamanho do jardim:\n";
        std::cout << "-jardim <linha> <coluna>\n\nComando: ";
        getline(std::cin, input);

        std::istringstream iss(input);
        std::string comando;
        iss >> comando >> l >> c;

        if (comando != "jardim") {
            std::cout << "Comando invalido! Use o formato: jardim <linha> <coluna>\n\n";
            continue;//volta while
        }

        if (iss.fail()) { // não conseguiu ler números
            std::cout << "Valores invalidos! Introduza numeros inteiros.\n\n";
            continue;
        }

        if (l <= 0 || c <= 0) {
            std::cout << "As dimensoes devem ser positivas.\n\n";
            continue;
        }

        if (l > 26 || c > 26) {
            std::cout << "O tamanho maximo permitido é 26x26.\n";
            std::cout << "Por favor introduza novamente.\n\n";
            continue; // volta ao início do while
        }

        // Se chegou aqui, os valores são válidos
        valido = true;
    }

    jardim = new Jardim(l,c); //nv const
    jardim->mostra();
}
Comando::~Comando() {
    delete jardim;
}
std::string Comando::obtemInput(std::string message) {
    std::string input;

    std::cout << message << "\n> ";
    std::getline(std::cin, input);

    return input;
}

bool Comando::executa() {
    std::string input;
    std::cout << "\n==========================/LISTA DE COMANDOS/==========================================\n";
    std::cout << "-avanca [n]        -lplantas     -colhe <l> <c>            -grava <nome>\n";
    std::cout << "-entra <l> <c>     -lplanta      -planta <l> <c> <tipo>    -recupera <nome>\n";
    std::cout << "-sai               -larea        -larga                    -apaga <nome>\n";
    std::cout << "                   -lsolo        -pega <n>                 -executa <nome-do-ficheiro>\n";
    std::cout << "                   -lferr        -compra <n>               -fim\n";
    std::cout << "======================================================================================\n";
    input = obtemInput("Comando:");

    std::istringstream iss(input);
    iss >> input ;

    if (input == "avanca") {
        int m;
        if (temInt(iss,m))// caso nao seja passado nada no 'n' assume como 1
            printf("Avanca em %d instantes",m);
        std::cout << "\nComando Invalido\n";

    }else if (input == "lplantas") {//lista TUDO acerca das plantas, e ate do solo onde elas estao
        std::cout << "\nLista de Plantas:\n";
        jardim->mostraPlantas();

    }else if (input == "lplanta") { //lista as propriedades da planta q encontrar na posicao l c (lplanta dc)
        std::cout << "\nPropriedades da planta:\n";

    }else if (input == "larea") {//lista as propriedades e consteudo de cada uma das posicoes q n estejam vazias
        std::cout << "\nPropriedade e Conteudo da area:\n";

    }else if (input == "lsolo") {
        char l, c;
        if (!temChar(iss,l) || !temChar(iss,c)) {
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        if (!Solo::eValido(l,c)){
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        std::cout << "\nCoisas que se encontram no solo:\n";

    }else if (input == "lferr") {
        std::cout << "\nFerramentas:\n";

    }else if (input == "colhe") {
        char l, c;
        if (!temChar(iss,l) || !temChar(iss,c)) {
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        if (!Solo::eValido(l,c)){
            std::cout << "\nSintaxe errada!\n";
        return true;
        }
        std::cout << "\nColhe planta:\n";

    }else if (input == "planta") {
        char l, c, tipo;
        if (!temChar(iss,l) || !temChar(iss,c) || !temChar(iss,tipo)) {
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        if (!Solo::eValido(l,c)){
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        std::cout << "\nColoca nova planta:\n";
        jardim->planta(l, c, 's');
        jardim->mostra();

    }else if (input == "larga") {
        std::cout << "\nLarga Ferramenta:\n";

    }else if (input == "pega") {
        int m;
        if (temInt(iss,m))
            printf("Pega em %d",m);
        std::cout << "\nComando Invalido\n";

    }else if (input == "compra") {
        std::cout << "\nCompra Ferramenta:\n";

    }else if (input == "entra") {
        char l, c;
        if (!temChar(iss,l) || !temChar(iss,c)) {
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        if (!Solo::eValido(l,c)) {
            std::cout << "\nSintaxe errada!\n";
            return true;
        }
        std::cout << "\nEntra na posicao:\n";

    }else if (input == "sai") {
        std::cout << "\nSai do jardim:\n";

    }else if (input == "grava") {
        std::cout << "\nGrava do programa\n";

    }else if (input == "recupera") {
        std::cout << "\nRecupera programa\n";

    }else if (input == "apaga") {
        std::cout << "\nApaga programa\n";

    }else if (input == "executa") {
        std::cout << "\nExecuta programa\n";

    }else if (input == "fim") {
        std::cout << "Fim do programa\n\nTrabalho Feito por:  Bruna Alves de Sousa   N 2022139713\n                     Ricardo Antonio Ribeiro Miguel   N 2022135245\n";
        return false;//sai

    }else {
        std::cout << "\nComando Invalido! Use um da Lista de Comandos.\n";
    }
    return true;
}

bool Comando::temInt(std::istringstream &iss, int &i) {
    std::string input;
    if (!(iss >> input)) return false; // nada para ler

    // Cria um novo stream a partir da string lida
    std::istringstream issTemp(input);
    int temp;

    // Verifica se consegue ler um int e se n h caracteres extras
    if (issTemp >> temp ) {
        i = temp;   //ao passar para o temp sei q é int
        return true;
    }

    return false;
}

bool Comando::temChar(std::istringstream &iss, char &c) {
    std::string input;
    if (!(iss >> input)) return false; // nada para ler

    // Verifica se ha exatamente um caractere
    if (input.size() == 1) {
        c = input[0];
        return true;
    }
    return false;
}
