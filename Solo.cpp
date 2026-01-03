//
// Created by bruni on 24/10/2025.
//

#include "Solo.h"
#include <cctype>
#include <iostream>
#include <iomanip>

//Construtor padrão
Solo::Solo(): planta(nullptr), ferramenta(nullptr) {
    agua = 80 + rand() % 21;        // [80, 100]
    nutrientes = 40 + rand() % 11;  // [40, 50]
}

//Contrutor com a posição
Solo::Solo(const Posicao& posicao) : p(posicao), planta(nullptr), ferramenta(nullptr) {
    agua = 80 + rand() % 21;
    nutrientes = 40 + rand() % 11;
}

//Construtor de letras
Solo::Solo(char l, char c) : planta(nullptr), ferramenta(nullptr) {
    p.setL(l - 'A');
    p.setC(c - 'A');
    agua = 80 + rand() % 21;
    nutrientes = 40 + rand() % 11;
}

//Destrutor
Solo::~Solo() {
    delete planta;
    delete ferramenta;
}

//====GETTERS====
Planta* Solo::getPlanta() { return planta; }
const Planta* Solo::getPlanta() const { return planta; }

Ferramenta* Solo::getFerramenta() { return ferramenta; }
const Ferramenta* Solo::getFerramenta() const { return ferramenta; }

Posicao Solo::getposicao() const { return p; }
Posicao Solo::getposicao() { return p; }

int Solo::getAgua() const { return agua; }
int Solo::getAgua() { return agua; }

int Solo::getNutrientesSolo() const { return nutrientes; }
int Solo::getNutrientesSolo() { return nutrientes; }

bool Solo::temPlanta() const {return planta != nullptr;}

bool Solo::temFerramenta() const { return ferramenta != nullptr; }

//====SETTERS====
bool Solo::setPlanta(Planta *novaPlanta) {  //Verifica se já está ocupada e retorna sucesso/falha
   if(planta == nullptr) {
       planta = novaPlanta;
       return true;
   }
    return false;
}

void Solo::setFerramenta(Ferramenta *novaFerramenta) {
    ferramenta = novaFerramenta;
}

Planta* Solo::removePlanta() {
    Planta* temp = planta;
    planta = nullptr;
    return temp;
}

Ferramenta* Solo::removeFerramenta() {
    Ferramenta* temp = ferramenta;
    ferramenta = nullptr;
    return temp;
}

void Solo::retiraAgua(int x) {
    if (x < 0) return;
    agua -= x;
    if (agua < 0) agua = 0;
}

// Adiciona água ao solo
void Solo::adicionaAgua(float x) {
    if (x <= 0) return;
    agua += (int)std::round(x);
}

// Retira nutrientes
void Solo::retiraNutrientes(int x) {
    if (x < 0) return;
    nutrientes -= x;
    if (nutrientes < 0) nutrientes = 0;
}

// Adiciona nutrientes
void Solo::adicionaNutrientes(float x) {
    if (x <= 0) return;
    nutrientes += (int)std::round(x);
}

bool Solo::eValido(char l, char c) {
    l = (char)std::tolower((unsigned char)l);
    c = (char)std::tolower((unsigned char)c);

    return (l >= 'a' && l <= 'z' && c >= 'a' && c <= 'z');
}


void Solo::mostraSolo() const {
    std::cout << "Agua: " << agua << " | Nutrientes: " << nutrientes << "\n";

    if (ferramenta)
        std::cout << "Ferramenta no chao: " << ferramenta->getNome()
                  << " ('" << ferramenta->getChar() << "')\n";
    else
        std::cout << "Ferramenta no chao: (nenhuma)\n";

    if (planta) {
        std::cout << "Planta: ";

        switch (planta->getChar()) {
            case 'r': std::cout << "Roseira"; break;
            case 'c': std::cout << "Cacto"; break;
            case 'e': std::cout << "Erva Daninha"; break;
            case 'x': std::cout << "Exotica"; break;
            default:  std::cout << "Desconhecida"; break;
        }

        std::cout << " ('" << planta->getChar()
                  << "') | Beleza: " << planta->getBeleza() << "\n";
    }
    else {
        std::cout << "Planta: (nenhuma)\n";
    }

}

Solo& Solo::operator=(const Solo& outro) {
    if (this == &outro) return *this;

    // Limpa o que existia antes para evitar fugas de memória
    delete planta;
    delete ferramenta;

    // Copia as características básicas
    this->p = outro.p;
    this->agua = outro.agua;
    this->nutrientes = outro.nutrientes;

    //CLONA os objetos (Deep Copy)
    if (outro.planta != nullptr)
        this->planta = outro.planta->clona();
    else
        this->planta = nullptr;

    if (outro.ferramenta != nullptr)
        this->ferramenta = outro.ferramenta->clona();
    else
        this->ferramenta = nullptr;

    return *this;
}

void Solo::mostraPlanta() const {
    if (!planta) {
        std::cout << "Nao existe planta nesta posicao.\n";
        return;
    }
    planta->mostrarInfoPlanta();
}