#include "conta.h"
#include "usuario.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, op, numero = 0, i=0, j;
    float valor = 0;
    char nome[20];
    char cpf[15];
    tUsuario user;
    tConta conta;


    scanf("%d", &n);
    tConta contas[n];

    scanf("%d", &op);
    while (op)
    {
        switch (op)
        {
        case 1:
            scanf("%d %f", &numero, &valor);
            for (j = 0; j < i; j++)
            {
                if (VerificaConta(contas[j], numero))
                {
                    contas[j] = SaqueConta(contas[j], valor);
                    break;
                }
            }
            break;
        case 2:
            scanf("%d %f", &numero, &valor);
            for (j = 0; j < i; j++)
            {
                if (VerificaConta(contas[j], numero))
                {
                    contas[j] = DepositoConta(contas[j], valor);
                    break;
                }
            }
            break;
        case 3:
            scanf("%s %s %d", nome, cpf, &numero);
            user = CriaUsuario(nome, cpf);
            conta = CriaConta(numero, user);
            contas[i] = conta;
            i++;
            break;
        case 4:
            printf("===| Imprimindo Relatorio |===\n");
            for (j = 0; j < i; j++)
            {
                ImprimeConta(contas[j]);
                printf("\n");
            }
            break;
        default:
            exit(0);
            break;
        }
        scanf("%d", &op);
    }
    return 0;
}
