#include <stdio.h>


void ImprimeInvertido(char* string);

int main () 
{

    char palavra[1000];

    while (scanf("%s", palavra) == 1)
    {
        ImprimeInvertido(palavra);
    }

    return 0;
}

void ImprimeInvertido(char* string)
{
    if (string[1] == '\0')
    {
        printf("%c", string[0]);
        string[0] = '\0';
    }
    else 
    {
        ImprimeInvertido(string+1);
    }
}

// int TamanhoString(char* string);

// int main()
// {
//     char string[1000];
//     scanf("%s", string);
//     printf("%s", string+1);
//     // int i = TamanhoString(string);
//     // printf("%d", i);

//     return 0;
// }

// int TamanhoString(char* string)
// {
//     int i = 0;
//     if (string[i] == '\0')
//     {
//         return 0;
//     }
//     else 
//     {
//         return TamanhoString(string+1) + 1;
//     }
// }