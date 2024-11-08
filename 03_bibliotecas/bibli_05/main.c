#include <stdio.h>
#include <string.h>

int main () 
{

    char str[1000];
    scanf("%[^\n]s", str);

    int tam = strlen(str);
    int i;
    for (i = 0; i < tam; i++)
    {
        str[i] = str[i] - 'a' + 'A';
    }
    printf("%s", str);

    return 0;
}