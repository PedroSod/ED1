
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
{
}
int main()
{
    int vetParam[] = {1, 2, 3};
    int size = sizeof(vetParam) / sizeof(int);
    imprimeVetor(vetParam, size);

    return 1;
}