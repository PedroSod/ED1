#include <stdlib.h>
#include <stdio.h>

int main()
{
    float l1, l2,l3;
    printf("lado 1:");
    scanf("%f", &l1);
    printf("lado 2:");
    scanf("%f", &l2);
    printf("lado 3:");
    scanf("%f", &l3);
    int isTriangulo = 0;
    if((l1 < l2+l3) && (l2 < l1+l3)  && (l3 < l2+l1)){
        isTriangulo = 1;
    }
    if(isTriangulo){
        printf("triangulo valido\n");
    }else{
        printf("Não é um triangulo validoa\n");
    }
    return 1;
}