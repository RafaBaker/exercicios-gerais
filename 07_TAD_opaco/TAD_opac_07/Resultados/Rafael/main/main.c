#include "data.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
    tData* d1 = CriaData();
    tData* d2 = CriaData();
    
    LeData(d1);
    LeData(d2);
    
    
    if (VerificaDataValida(d1) && VerificaDataValida(d2))
    {
        printf("Primeira data: ");
        ImprimeDataExtenso(d1);
        printf("Segunda data: ");
        ImprimeDataExtenso(d2);
        
        if(ComparaData(d1, d2) == 1)
        {
            printf("A segunda data eh mais antiga");
        }
        else if(ComparaData(d1, d2) == -1)
        {
            printf("A primeira data eh mais antiga");
        }
        else 
        {
            printf("As datas sao iguais");
        }
        printf("\n");
    
        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(d1, d2));
    }
    else
    {
        printf("A primeira e/ou segunda data(s) invalida(s)");
    }

    LiberaData(d1);
    LiberaData(d2);

    return 0;
}
