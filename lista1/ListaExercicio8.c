#include <stdlib.h>
#include <stdio.h>

int main()
{
    float n1,n2,produto,divisao;
    
        printf("Digite um  n1: ");
        scanf("%f", &n1);
        printf("Digite um  n2: ");
        scanf("%f", &n2);
        for(int i = 0; i < n2; i++){
            produto += n1;
        }
        for(int i = 1;n1 > 0; i++){
            n1 -= n2;
            divisao = i;
        }
        printf("Produto: %f\n", produto);
        printf("Divisão: %f\n", divisao);
        return 1;
}