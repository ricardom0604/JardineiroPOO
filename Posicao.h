//
// Created by bruni on 24/10/2025.
//

#ifndef POSICAO_H
#define POSICAO_H



class Posicao {
    int l, c;
    public:
        Posicao(int l, int c);   //é para usar devido as poicoes dos arrays
        Posicao(char l, char c);
        ~Posicao();
    int getL();
    void setL(int l);
    int getC(); //se a var l e c é privada preciso de ter metodos
    void setC(int c);
    static bool eValido(char l, char c);  //posicao::eval n percence a um objeto mas sim a uma classe

};



#endif //POSICAO_H
