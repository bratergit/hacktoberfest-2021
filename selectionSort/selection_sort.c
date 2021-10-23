#include <stdio.h>
#include <stdlib.h>

int arr [] = {101010101,1,4444,2,23413,34,242,34,13,13,41,341,34,134,13,41,23,1,12,2,23,4,34,23,423,42,34,234,234,2,4,7,77,7,7,7,7,99,89,34,77,100,78,34,55,65,9,-10};
int tam = sizeof(arr) / sizeof(int);

int main(void)
{
  int i, j, aux;

 for (i = 0; i < tam; i++)
  {
    printf("%d ",arr[i]);
  }
 printf("\n");

  for (i = 0 ; i < tam; i++)
  {
    
    for (j = i+1; j < tam; j++)
    {
      if (arr[i] > arr[j])
      {
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
      }
    }

  }

  for (i = 0; i < tam; i++)
  {
    printf("%d ",arr[i]);
  }
  
  printf("\n");



return 0;

}

