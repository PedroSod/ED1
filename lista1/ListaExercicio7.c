#include <stdlib.h>
#include <stdio.h>

int main()
{
    float chico = 1.50;
    float zeh = 1.20;
    int cont = 0;
    while (chico > zeh)
    {
        zeh += 0.04;
        chico += 0.02;
        cont++;
    }
    printf("Anos: %d\n", cont);
    return 1;
}