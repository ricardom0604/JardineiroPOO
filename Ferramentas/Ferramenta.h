#ifndef FERRAMENTA_H
#define FERRAMENTA_H
#include <string>

class Solo;
class Jardineiro;

using namespace std;

class Ferramenta{
protected:
    static int contadorNS;
    int nSerie;
    char character;
    string nome;
public:
    Ferramenta(const string &nome, char c);
    virtual ~Ferramenta();
    virtual Ferramenta* clona() const = 0; //para retificar a situação quando recuperamos o jardim (1/4)jardi

    //===GETTERS===
    int getnSerie() const;
    char getChar() const;
    string getNome() const;

    //===SETTERS===
    void setnSerie(int nSerie);
    void setChar(char c);
    void setNome(string n);

    virtual void usar(Solo &solo, Jardineiro& jardineiro) = 0;
    virtual bool estaGasta() const = 0;
    virtual void mostrarInfo() const;



};

#endif //FERRAMENTA_H
