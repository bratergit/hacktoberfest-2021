#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

/*
  // tentiva de thread em c 
  pthread_t thread_id;
  pthread_create(&thread_id, NULL,arrSorted = bubbleSort(tam,arr),NULL);
  pthread_join(thread_id,NULL);

  for(i = 0; i < tam; i++)
  {
    printf("%d, ", arrSorted[i]);
  }
  printf("\n");
  // https://www.google.com/search?q=learn+thread+in+c+for+dummies&oq=learn+thread+in+c+for+dummies&aqs=chrome..69i57.6115j0j4&sourceid=chrome&ie=UTF-8

*/

int verificaArg(int argc, char **argv);

int rdtsc();

int *geraRandom(int tam);

int *bubbleSort(int tam, int *arr);

//void *buscaBinaria(int element, int *arr, int tam);

int main(int argc, char **argv)
{
  int tam, *arr, *arrSorted, i;
  // 
  if (verificaArg(argc, argv) * -1 > 0)
  {
    printf("Program terminated!\n");
    return -1;
  }
  tam = atoi(argv[1]);
  printf("\nRandom Array with %d elements\n\n", tam);
  // gera array aleatorio
  arr = geraRandom(tam);
  for(i = 0; i < tam; i++)
  {
    printf("%d, ",arr[i]);
  }
  printf("\n\n");

  printf("\nSorted array with Bubble Sort Algorithm\n\n");
  // implementa o bubble sort
  arrSorted = bubbleSort(tam,arr);
  for(i = 0; i < tam; i++)
  {
    printf("%d, ", arrSorted[i]);
  }
  printf("\n");

  // programa de busca binária
 // int element;
  //printf("\nWhich element should the program return?\n");
 // scanf("%d",&element);
  //buscaBinaria(element,arrSorted,tam);


  free(arr);
  free(arrSorted);
}

int verificaArg(int argc, char **argv)
{
  if (argc < 2)
  {
    printf("usage ./bubble 'type a number'\n");
    return -1;
  }
  if (argc == 2)
  {
    if(atoi(argv[1]) <= 0)
    {
      printf("Should be a number bigger than zero ( 0 ) and less than 2147483647, also it should not be a letter\n");
      return -1;     
    }
    if(atoi(argv[1]) > 0 && atoi(argv[1]) < 100000000)
    {
      printf("Size of the array = %d\n", atoi(argv[1]));
      return atoi(argv[1]);
    }
    
  } 
  return -1;  
} 

int rdtsc() 
{ 
  __asm__ __volatile__("rdtsc"); 
} 

int *geraRandom(int tam)
{
  int i, *arr, aux = 0;
  arr = (int*) malloc (sizeof(int) * tam);

  for(i = 0; i < tam; i++)
  {
    srand(rdtsc());
    arr[i] = rand() % tam + 1;
  }
  return arr;
}

int *bubbleSort(int tam, int *arr)
{
  int i, j, aux, *arr_aux;
  arr_aux = (int*) malloc(sizeof(int)*tam);
  for(i = 0; i < tam; i++)
  {
    for(j = 0; j < tam -i -1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
      }
    }
  }
  for(i = 0; i< tam; i++)
  {
    arr_aux[i] = arr[i];
  }

  return arr_aux;
}

/*void *buscaBinaria(int element, int *arr, int tam)
{
  // variáveis para a busca binária
  int start = 0, end = tam -1, middle = end / 2;
  int i, aux = 0;
  while (start <= end)
  {
    if (element == arr[middle])
    {
      printf("Number found \n");
      if (aux == 0)
        aux += 1;
      printf("It take %d loops to be found\n", aux);
      break;
    }
    else if (element > arr[middle])
    {
      printf("Searching ... %d > %d \n", element, arr[middle]);
      start = middle + 1;
      middle = (start + end) / 2;
      aux += 1;
    }
    else if (element < arr[middle])
    {
      printf("Searching ... %d > %d \n", element, arr[middle]);
      end = middle - 1;
      middle = (start + end) / 2;
      aux += 1;
    }
  }
  if(start != end)
    printf("\n\nThe number %d is not in the array\n\n", element);
}
*/