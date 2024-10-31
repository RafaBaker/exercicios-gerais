#include <stdio.h>

int palindromo(char *string, int tamanho);
int TamanhoString(char* string);

int main () {

    char palavra[1000];
    int flag = -1, tam; 
    while (scanf("%s", palavra) == 1)
    {
        tam = 0;
        tam = TamanhoString(palavra);
        flag = palindromo(palavra, tam);
        if (flag)
        {
            printf("SIM\n");
        }
        else 
        {
            printf("NAO\n");
        }
    }

    return 0;
}

int palindromo(char *string, int tamanho)
{
    if (tamanho <= 0)
    {
        return 1;
    }
    if (string[0] != string[tamanho-1])
        return 0;
    else 
    {
        return palindromo(string+1, tamanho-2);
    }
}

int TamanhoString(char* string)
{
    int i = 0;
    if (string[i] == '\0')
    {
        return 0;
    }
    else 
    {
        return TamanhoString(string+1) + 1;
    }
}