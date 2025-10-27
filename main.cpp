#include <iostream>

#include "Jardim.h"
#include "Comando.h"

int main()
{
    Comando cmd;
    Jardim j = cmd.criaJardim();

    j.mostra();

    return 0;
}
