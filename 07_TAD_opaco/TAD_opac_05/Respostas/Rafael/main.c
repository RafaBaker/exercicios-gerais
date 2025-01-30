#include "banco.h"
#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

int main () {

    tBanco* banco = CriaBanco();
    DestroiBanco(banco);

    return 0;
}