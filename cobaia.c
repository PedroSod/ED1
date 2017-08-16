#include <stdlib.h>
#include <stdio.h>

int main()
{
	// printf("Ola mundo!!!\n");
	// printf("float:%d int:%d char:%d	double:%d unsigned int:%d\n",sizeof(float), sizeof(int), sizeof(char), sizeof(double), sizeof(unsigned int));	


	// char v [10];
	// fgets(v, 5, stdin);
	// __fpurge(stdin);
	// printf("%s\n",v);

	 // int n = 0;
	 // scanf("%d",&n);
	 // printf("Numero de entrada: %d\n",n);

	// char frase [10], x [10];
	// fgets(frase, 5, stdin);
	// printf("%s\n",frase);
	// scanf("%s", &x);
	// printf("%s\n",x);
	// int idade = 0;
	// char nome [40];

	// printf("Digite sua idade:");
	// scanf("%d",&idade);
	// __fpurge(stdin);
	// printf("Digite seu nome:");
	// fgets(nome, 40, stdin);
	// nome[strlen(nome)-1]='\0';
	// printf( "idade:%d\nnome:[%s]\n",idade, nome);

	char nome [30];
	strcpy(nome,"Pedro");
	char nome2 [30];
	fgets(nome2, 40, stdin);
	nome2[strlen(nome2)-1]='\0';
	printf("%s\n", nome2);
	if(!strcmp(nome,nome2))
	{
		printf("nomes iguais\n");
	}
	else
	{
		printf("nomes diferentes\n");
	}
	return 1;
}