#include <stdlib.h>
#include <stdio.h>

int main()
{
    char c1,c2;
    scanf("%c",&c1);
 //   __fpurge(stdin); //comente essa linha
    scanf("%c",&c2);
    printf("(%c)(%c)",c1,c2);

    return 1;
}