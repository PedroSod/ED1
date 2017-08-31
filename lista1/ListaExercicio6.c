#include <stdlib.h>
#include <stdio.h>

float calcPeso(float peso, float gravidade)
{
    peso = peso / 9.80665 ;
    return (peso * gravidade);
}
int main()
{
    int condicao;
    float pesoNaTerra;

    printf("Digite um  peso: ");
    scanf("%f", &pesoNaTerra);

    printf("Digite um valor de 1 a 6: ");
    scanf("%d", &condicao);

    switch (condicao)
    {
    case 1:
        printf("Peso em Mercurio: %f\n", calcPeso(pesoNaTerra, 0.37));
        break;
    case 2:
        printf("Peso em Venus: %f\n", calcPeso(pesoNaTerra, 0.88));
        break;
    case 3:
        printf("Peso em Marte: %f\n", calcPeso(pesoNaTerra, 0.38));
        break;
    case 4:
        printf("Peso em Jupiter: %f\n", calcPeso(pesoNaTerra, 2.64));
        break;
    case 5:
        printf("Peso em Saturno: %f\n", calcPeso(pesoNaTerra, 1.15));
        break;
    case 6:
        printf("Peso em Urano: %f\n", calcPeso(pesoNaTerra, 1.17));
        break;
    default:
        printf("Valor invalido!\n");
    }

    return 1;
}