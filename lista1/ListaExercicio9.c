#include <stdlib.h>
#include <stdio.h>
void imprimeVetor(int vet[], int tamanho)
{
    printf("Vetor{");
    for (int i = 0; i < tamanho; i++)
    {

        printf("%d", vet[i]);
        if ((i +1) != tamanho)
        {
            printf(",");
        }
    }
    printf("}\n");
}
int main()
{

    int vet1[5], vet2[5], vetSoma[5];
    printf("Vetor 1: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vet1[i]);
    }
    printf("Vetor 2: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vet2[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        vetSoma[i] = vet1[i] + vet2[i];
    }
    printf("Vetor 1: ");   
    imprimeVetor(vet1, 5);
    printf("Vetor 2: ");   
    imprimeVetor(vet2, 5);
    printf("Vetor Soma: ");   
    imprimeVetor(vetSoma, 5);
    return 1;
}