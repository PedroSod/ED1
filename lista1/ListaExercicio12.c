#include <stdlib.h>
#include <stdio.h>

int main()
{

	char nome2 [30];
	fgets(nome2, 40, stdin);
	int size = strlen(nome2) -1;
    printf("%d\n", size);
    return 1;
}