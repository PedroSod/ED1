
#include <stdlib.h>
#include <stdio.h>

int fatorial (int x){
    if(x<0)
    {
        puts("erro, fatorial de numero negativo");
        return 0;
    }
    else if( x==0)
    {
        return 1;
    }  
    else{
        return x * fatorial(x - 1);
    }
}

int main(int argc, char *argv[ ] )
{
    printf("%d \n", fatorial(atoi(argv[1])));
    return 1;
}