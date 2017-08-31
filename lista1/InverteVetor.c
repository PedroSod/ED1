
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

void inverteVetor(int vet[], int tamanho)
{    int start = 0, end = tamanho - 1, temp;
    imprimeVetor(vet, tamanho);
    if (start < end) {
        temp = vet[start];
        vet[start] = vet[end];
        vet[end] = temp;  
        inverteVetor((vet+1), 
            tamanho - 2);
    }    
}

int main()  
{
    int vetParam[] = {1,2,3,4,5,6,7};
    int size = sizeof(vetParam) / sizeof(int);
    imprimeVetor(vetParam, size);
    inverteVetor(vetParam, size);
    imprimeVetor(vetParam, size);
    inverteVetor(vetParam, size);
    imprimeVetor(vetParam, size);
    return 1;
}