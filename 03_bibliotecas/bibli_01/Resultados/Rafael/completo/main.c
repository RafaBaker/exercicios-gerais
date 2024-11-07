#include <stdio.h>
#include "esferas_utils.h"

int main ()
{
    float r=0, v=0, a=0;
    scanf("%f", &r);

    v = calcula_volume(r);
    a = calcula_area(r);
    printf("Area: %.2f\nVolume: %.2f\n", a, v);

    return 0;
}