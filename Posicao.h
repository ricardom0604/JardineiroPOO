//
// Created by bruni on 24/10/2025.
//

#ifndef POSICAO_H
#define POSICAO_H



class Posicao {
    int l, c;
    public:
        Posicao(int l, int c);
        Posicao(char l, char c);
        ~Posicao();
    int getL();
    void setL(int l);
    int getC();
    void setC(int c);
    static bool eValido(char l, char c);

};



#endif //POSICAO_H
