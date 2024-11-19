#include "string_utils.h"
#include <stdio.h>

int string_length(char *str)
{
    if (str[0] == '\0')
        return 2;
    return 1 + string_length(str+1);
}

void string_copy(char *src, char *dest)
{
    sprintf(dest, "%s", src);
}

void string_upper(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

void string_lower(char *str)
{
    int i;
    for (i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

void string_reverse(char *str)
{
    int i, j, tam;
    tam = string_length(str)-3;
    char cpy[tam];
    string_copy(str, cpy);
    for (i = tam, j = 0; i >= 0; i--, j++)
    {
        str[i] = cpy[j];
    }
}
