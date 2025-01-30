#include "utils.h"

int TrocaInterios(int * n1, int * n2)
{
    if (*n1 > *n2)
    {
        int aux = *n1;
        //printf("aux: %d");
        *n1 = *n2;
        *n2 = aux;
        return 1;
    }
    return 0;
}

// int main()
// {
//     int n1 = 1, n2 = 2;


//     return 0;
// }