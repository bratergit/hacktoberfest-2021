#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int *randomArray(int tam);
int rdtsc() ;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage ./linear number\n");
        return 1;
    }
    int tam = atoi(argv[1]), *array, i, element;
    array = randomArray( tam );
    printf("\n\nLINEAR SEARCH\n\n");
    printf("[ ");
    for(i = 0; i < tam; i++)
    {
        printf("%d, ",array[i]);
        if(i==tam-1)
        {
            printf("%d",array[i]);
        }
    }
    printf(" ]\n\n");

    printf("Which element should I find in this random array => ");
    scanf("%d",&element);
   
    for(i = 0; i< tam; i++)
    {
        if(element == array[i])
        {
            printf("Found => %d , i => %d\n",array[i],i+1);
            return 0;
        }
    }
        
    

    printf("\n");
    return 0;  
}

int *randomArray(int tam)
{
    int i, *arr;
    arr = (int*) malloc (sizeof(int)* tam);
    for(i = 0; i < tam; i++)
    {
        srand(rdtsc());
        arr[i] = rand() % tam + 1;
    }
    return arr;

}
int rdtsc() 
{ 
  __asm__ __volatile__("rdtsc"); 
} 

