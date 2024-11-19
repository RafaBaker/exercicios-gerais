#include <stdio.h>
#include "string_utils.h"

int main()
{
    int op;
    char str[1000];
    scanf("%[^\n]s", str);
    while(1)
    {
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &op);
        if (op == 1)
        {
            int tam = string_length(str)+1;
            printf("Tamanho da string: %d\n\n", tam);
        }
        else if (op == 2)
        {
            printf("String copiada: %s\n\n", str); //nao entendi essa opção
        }
        else if (op == 3)
        {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n", str);
        }
        else if (op == 4)
        {
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n", str);
        }
        else if (op == 5)
        {
            string_reverse(str);
            printf("String invertida: %s\n\n", str);
        }
        else if (op == 6)
            exit(0);
    }
    return 0;
}