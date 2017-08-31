#include <stdlib.h>
#include <stdio.h>

void leString(char entrada[], int t)
{
    fgets(entrada, t, stdin);
    entrada[strlen(entrada) - 1] = '\0';
}

typedef struct
{
    char rua[100];
    char cep[9];
    char cidade[50];
    int numero;
} endereco;
typedef struct
{
    char nome[100];
    int idade;
    char telefones[5][9];
} pessoa;

pessoa lePessoa(pessoa p)
{
    int nroTel;
    printf("Digite nome:");
    leString(p.nome, 50);
    printf("Digite a idade:");
    scanf("%d", &(p.idade));
    printf("Quantos telefones:");
    scanf("%d", &nroTel);
    for (int i = 0; i < nroTel; i++)
    {
        __fpurge(stdin);
        printf("Digite o telefone%d:", (i + 1));
        leString(p.telefones[i], 9);
    }
    return p;
}
void mostraPessoa(pessoa p)
{
    printf("__________________________\n");
    printf("Nome:%s\n", p.nome);
    printf("Idade:%d\n", p.idade);
    for (int j = 0; j < 5; j++)
    {
        if (!p.telefones[j][0] == '\0')
            printf("Telefone%d:%s\n", (j + 1), p.telefones[j]);
    }
}
int main()
{
    pessoa p[2];
    int n;
    for (int i = 0; i < 2; i++)
    {
        p[i] = lePessoa(p[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        mostraPessoa(p[i]);
    }
      return 1;
}