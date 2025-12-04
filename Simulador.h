#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <string>


class Comando;
class Jardim;
class Jardineiro;

class Simulador {
    Comando* comando;
    Jardim* jardim;
    Jardineiro* jardineiro;
public:
    Simulador();
    ~Simulador();

    void roda();

    bool criaJardim(int l,int c);
    bool plantar(char tipo, int l, int c);

    Jardim* getJardim() const {
        return jardim;
    }

};



#endif