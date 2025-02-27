#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fila.h"
#include "movel.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int qtd;
    char comando[30];

    Fila* f = FilaConstruct();
    tMovel* m;

    scanf("%d", &qtd);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%s ", comando);
        //printf("comando: %s\n", comando);
        if (!strcmp(comando, "ENTRADA"))
        {
            m = LeMovel();
            //printf("movel na entrada: ");
            //ImprimeMovel(m);
            FilaPush(f, m);
            //DestroiMovel(m);
        }
        else if (!strcmp(comando, "PRODUZIR"))
        {
            m = (tMovel*)FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }
    //DestroiMovel(m);
    FilaDestroy(f, DestroiMovel);

    return 0;
}