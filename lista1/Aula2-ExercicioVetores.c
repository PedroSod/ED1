
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
    int temp;
    for(int i = 0; i < --tamanho ; i++){
        temp = vet[i];
        vet[i] = vet[tamanho];
        vet[tamanho] = temp;
    }
}
void maiorValor(int vet[], int tamanho)
{
    int temp = vet[0];
    for(int i = 0; i < tamanho ; i++){  
        if(temp < vet[i]){
            temp = vet[i];
        }       
    }
    printf( "Maior Valor:%d\n",temp);
}
int main()  
{
    int vetParam[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(vetParam) / sizeof(int);
    imprimeVetor(vetParam, size);
    maiorValor(vetParam, size);
    //inverteVetor(vetParam, size);
    //imprimeVetor(vetParam, size);
    return 1;
}