
#include <stdlib.h>
#include <stdio.h>

int arr_sum( int arr[], int n )
{ 
    if (n < 0) {
         return 0;
    }
//printf("\n arra:%d\n",arr[n]);
    return arr[n] + arr_sum(arr, n - 1);
}

int main(int argc, char *argv[ ] )
{
    int arr[argc -1];
    
    for(int i =0; i < argc - 1; i ++)
    {
        arr[i] = atoi(argv[i+1]);
    }
    int sum;
    sum = arr_sum(arr,4);
    printf("\nsum is:%d\n",sum);
    return 1;
}