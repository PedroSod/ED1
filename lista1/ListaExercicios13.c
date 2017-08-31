#include <stdlib.h>
#include <stdio.h>

int main()
{

	char frase [30];
	fgets(frase, 40, stdin);
    int size = strlen(frase) -1;
    for(int i = 0; i < size; i ++){
        if((frase[i] == 'a') || (frase[i] == 'e') || (frase[i] == 'i') ||
         (frase[i] == 'o') || (frase[i] == 'u')){
            frase[i] = '*';
        }
    }

	printf( "%s\n",frase);
    return 1;
}