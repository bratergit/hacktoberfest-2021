#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// gera um array de números aleatórios 
int *randArr(int tamanho)
{
  srand(time(NULL));
  int i, *arr;
  arr = (int*) malloc (sizeof(int) * tamanho);
  for(i = 0; i < tamanho; i++)
  {
    arr[i] = rand() % tamanho + 1;
  }
  return arr;  
}

// selection sort 
int *sort(int *array, int size)
{
  int i, j, aux, *aux_array;
  aux_array = (int*) malloc (sizeof(int) * size);
  for (i = 0; i < size; i++)
  {
    for (j = i+1; j < size;j++)
    {
      if (array[i] > array[j])
      {
        aux = array[j];
        array[j] = array[i];
        array[i]=aux;
      }
    }
    aux_array[i] = array[i];
  }
    return aux_array;  
}

int binary_search(int *array, int tam, int elemento)
{
  // variáveis da busca binária
  int target, start = 0, end = tam -1, middle = end / 2;
  int i, aux = 0;
  while(start <= end)
  {
    if (elemento == array[middle])
    {
      printf("Elemento encontrado array[%d] = %d\n",middle,elemento);
      if(aux == 0)
          aux += 1;
      printf("Quantidade de passagens para achar o elemento foi de => %d\n",aux);
      return elemento;
    }
    else if (elemento > array[middle])
    {
      printf("fazendo busca...%d > %d\n",elemento, array[middle]);
      start = middle+1; 
      middle = (start + end) / 2;
      aux +=1;
    }
    else if (elemento < array[middle])
    {
      printf("fazendo busca...%d < %d\n", elemento, array[middle]);
      end = middle -1;
      middle = (start + end) / 2;
      aux +=1;
    }    
  }
  return -1;
}

int main(int argc, char **argv)
{
  // variável tempinho para medir o tempão
  clock_t tempinho;
  double tempao;

  // variáveis de criação do array e também de ordenação do array
  int *p, *k, i, tam, elemento;  

  // verifica se foi passado a quantidade correta de argumentos
  if (argc < 2)
  {
    printf("Usar ./binary numero entre 0 a 500\n");
    return 1;
  }
  tam = atoi(argv[1]);
  printf("tamanho do array eh %d\n\n",tam);

  // tempinho começa a contar o tempão
  tempinho = clock();
  p = randArr(tam);
  printf("GERAÇÃO DO ARRAY SEMENTE\n");
  for (i = 0; i < tam; i++)
  {
    printf("%d ", p[i]);
  }
  tempinho = clock() -tempinho;
  tempao = ((double)tempinho)/CLOCKS_PER_SEC;

  printf("\nTempo gasto em segundos para gerar o array => %lf\n",tempao);

  printf("\n");
  tempinho = clock();
  printf("ORDENAÇÃO DO ARRAY GERADO \n");
  // k é o array inicial ordenado em ordem crescente
  k = sort(p, tam);
  for (i = 0; i < tam; i++)
  {
    printf("%d ", k[i]);
  }
  printf("\n");
  tempinho = clock() - tempinho;
  tempao = ((double)tempinho)/CLOCKS_PER_SEC;
  printf("\nTempo gasto em segundos para ordenar o array => %lf\n",tempao);

  printf("\n\nBUSCAR ATRAVÉS DE BUSCA BINÁRIA O NÚMERO DESEJADO\n");
  printf("Qual elemento quer buscar? Digite aqui => ");

  scanf("%d",&elemento);
  tempinho = clock();
  // achou recebe o retorno da função binary_search
  int achou = binary_search(k,tam,elemento);
  // verificação do retorno da função binary_search
  if (achou == -1)
  {
    printf("\n%d não esta presente no array\n",elemento);
  }

  tempinho = clock() - tempinho;
  tempao = ((double)tempinho)/CLOCKS_PER_SEC;
  printf("\nTempo gasto em segundos para o binary Search => %lf\n",tempao);

  // desalocando a memória
  free(p);
  free(k);

  printf("\n================== END =================\n");
  return 0;
}