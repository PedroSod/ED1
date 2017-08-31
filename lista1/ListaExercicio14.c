#include <stdlib.h>
#include <stdio.h>

int main()
{

	char frase [40];
	fgets(frase, 40, stdin);
    int size = strlen(frase) -1;
    int palavras = 1;
    int letra = 1;
    for(int i = 0; i < size; i ++){
        if(frase[i] == ' ') {
            letra = 0;
        }else{
            if(letra==0){
                palavras ++;
                letra =1;
            }
        }
    }

	printf( "%d\n",palavras);
    return 1;
}