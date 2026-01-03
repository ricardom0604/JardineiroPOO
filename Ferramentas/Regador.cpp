#include "Regador.h"

#include <iostream>

#include "Settings.h"
#include "Solo.h"

class Ferramenta;

bool Regador::estaGasta() const{ return aguaAtual <=0;}

void Regador::mostrarInfo() const {
    Ferramenta::mostrarInfo();
    std::cout << "  Agua restante: " << aguaAtual << "\n";
}
void Regador::usar(Solo& solo, Jardineiro&) {
    if (aguaAtual <= 0) return;

    solo.adicionaAgua(Settings::Regador::dose);
    aguaAtual -= Settings::Regador::dose;

    if (aguaAtual < 0) aguaAtual = 0;
}
