//
// Created by bruni on 24/10/2025.
//

#ifndef POSICAO_H
#define POSICAO_H
#define PLANTA_H


class Planta;

class Solo {
    int l, c;
    int agua;
    int nutrientes;
    Planta* planta;


    public:
        Solo();
        Solo(int l, int c);   //é para usar devido as poicoes dos arrays
        Solo(char l, char c);
        ~Solo();
    int getL();
    void setL(int l);
    int getC(); //se a var l e c é privada preciso de ter metodos
    void setC(int c);
    static bool eValido(char l, char c);  //posicao::eval n percence a um objeto mas sim a uma classe
    Planta *getPlanta();
    void setPlanta(Planta* planta);
};



#endif //POSICAO_H
