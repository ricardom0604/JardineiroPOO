#include <iostream>

#include "Jardim.h"
#include "Comando.h"

int main()
{
    Jardim j;
    Comando c;
    j.mostra();
    while (true) {
        if (!c.executa())
            break;
    }

    return 0;
}
