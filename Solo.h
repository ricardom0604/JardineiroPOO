//
// Created by bruni on 24/10/2025.
//

#ifndef SOLO_H
#define SOLO_H
#include "Planta.h"
#include "Posicao.h"

class Jardim;

class Solo {
    Posicao p;
    int agua;
    int nutrientes;
    Planta* planta;

public:
    Solo();
    Solo(const Posicao& p);   //é para usar devido as posicoes dos arrays
    Solo(char l, char c);
    ~Solo();


    void retiraNutrientes(int absorcao_nutrientes);
    void adicionaAgua(float x);
    void adicionaNutrientes(float x);
    void retiraAgua(int absorcao_agua);


    //====GETTERS=====
    Posicao getposicao();
    int getNutrientesSolo();
    int getAgua();
    Planta *getPlanta();

    bool temPlanta();
    bool temPlanta() const;

    //====SETTERS====
    bool setPlanta(Planta *novaPlanta);

    Planta* removePlanta(); // Retorna o ponteiro removido
    static bool eValido(char l, char c);  //posicao::eval n percence a um objeto mas sim a uma classe

};

#endif
