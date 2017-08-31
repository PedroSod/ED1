#include <stdlib.h>
#include <stdio.h>

void alteraTamanho(int vet[], int size, int newSize)
{
    int *p,i;
    int vet2[size2];
    p = (int*)calloc(novoTam,sizeof(int)*novoTam);
    
    for (int i = 0; i < size2; i++)
    {
        vet2[i] = vet[i];
    }
    free(vet);
    vet = malloc(size);
    for (int i = 0; i < size; i++)
    {
       vet[i] = vet2[i];
    }
    
}
int main()
{

    int vet = {1,2};
    int size = 3;
    imprimeVetor(vet,2);
    alteraTamanho(vet, size);
    imprimeVetor(vet,size);

    return 1;
}