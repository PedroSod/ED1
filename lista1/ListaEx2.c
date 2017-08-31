#include <stdlib.h>
#include <stdio.h>

int main()
{
    float n =  7.8954 ;
    float n2 = 3456.345;

    printf("%f \t%f\n",n,n2);
    printf("%.15f \t%.3f\n",n,n2);
    printf("%10f \t%10f\n",n,n2);
    printf("%10.2f \t%10.2f\n",n,n2);

    return 1;
}