#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

int main ()
{
    printf("tad_gen_02\n");
    
    int tipo = -1, op = -1, qtd, i= 0;
    tGerenciador* geren = CriaGerenciador();
    tPacote* pac = NULL;

    while (1)
    {
        // i++;
        // if (i == 10)
        //     break;
        printf("\nEscolha uma opcao:\n\t(1) Cadastrar um novo pacote\n\t(2) Imprimir um pacote específico\n\t(3) Imprimir todos os pacotes e sair\n");
        scanf("%d", &op);
        if (op == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &tipo, &qtd);
            //printf("tipo e qtd: %d %d\n", tipo, qtd);
            if (!(tipo == 0 || tipo == 1))
            {
                printf("\nDigite um tipo valido!");
                continue;
            }

            if (tipo == 0)
                tipo = 2;
            pac = CriaPacote(tipo, qtd);
            LePacote(pac);
            //ImprimePacote(pac);
            AdicionaPacoteNoGerenciador(geren, pac);
        }
        else if (op == 2)
        {
            printf("nao sei\n");
        }
        else if (op == 3)
        {
            ImprimirTodosPacotes(geren);
            break;
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!");
            continue;
        }
    }
    DestroiGerenciador(geren);

    return 0;
}