#include "banco.h"
#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

int main () {

    tBanco* banco = CriaBanco();
    char com = '\0';
    while (com != 'F')
    {
        scanf("%c", &com);
        scanf("[^\n]");
        scanf("%*c");

        switch (com)
        {
        case 'A':
            AbreContaBanco(banco);
            break;
        case 'S':
            SaqueContaBanco(banco);
            break;
        case 'D':
            DepositoContaBanco(banco);
            break;
        case 'T':
            TransferenciaContaBanco(banco);
            break;
        case 'R':
            ImprimeRelatorioBanco(banco);
            break;
        default:
            //printf("opção invalida");
            break;
        }
    }
    DestroiBanco(banco);

    return 0;
}