//
// Created by bruni on 11/12/2025.
//

#ifndef POSICAO_H
#define POSICAO_H


class Posicao {
     int l,c;

public:
     Posicao();

     Posicao(int l, int c);
//====GETTERS====
     int getL() const;
     int getC() const;

//====SETTERS====
     void setL(int l);
     void setC(int c);
};



#endif //POSICAO_H
