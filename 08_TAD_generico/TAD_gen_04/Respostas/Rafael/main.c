#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main ()
{
    char flag = 0;
    int f = 1;
    tBanco* banco = CriaBanco();
    tAgencia* ag = NULL;
    tConta* conta = NULL;
    LeBanco(banco);
    while (f)
    {
        scanf("%c", &flag);


        switch (flag)
        {
        case 'A':
            ag = CriaAgencia();
            LeAgencia(ag);
            AdicionaAgencia(banco, ag);

            break;
        case 'C':
            conta = CriaConta();
            LeConta(conta);
            int n = 0;
            scanf("%d\n", &n);

            InsereContaBanco(banco, n, conta);
            break;

        case 'F':
            f = 0;
            break;

        default:
            break;
        }
    }

    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);

    return 0;
}