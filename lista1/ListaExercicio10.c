#include <stdlib.h>
#include <stdio.h>

int main()
{

        for(int i = 0; i < 10; i++){
            for(int j = 0; j <= i; j++){
                printf("*");
            }
            printf("\n");
            
        }
        printf("\n");
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < (10 - i); j++){
                printf("*");
            }
            printf("\n");
            
        }
    return 1;
    }