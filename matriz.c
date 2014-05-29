#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "matriz.h"

typedef struct matriz {
  int **valor;
  int nr_linhas, nr_colunas;
} matriz_t;

matriz_t *matriz_criar( int nr_linhas, int nr_colunas )
{

  matriz_t *matriz = (matriz_t*)malloc(sizeof(matriz_t));
  matriz->nr_linhas = nr_linhas;
  matriz->nr_colunas = nr_colunas;

  int i;
  
  matriz->valor = (int **)malloc(nr_colunas * sizeof(int *));
  
  for (i = 0; i < nr_colunas; i++)
	matriz->valor[i] = (int *)malloc(nr_linhas * sizeof(int));

  return matriz;
}

int matriz_obter_nr_linhas( matriz_t *matriz )
{
  return matriz->nr_linhas;
}

int matriz_obter_nr_colunas( matriz_t *matriz )
{
  return matriz->nr_colunas;
}

void matriz_destruir( matriz_t *matriz )
{
  int i;
  int n = matriz->nr_colunas;
  for (i = n - 1; i >= 0; i--)
        free(matriz->valor[i]);
  free(matriz->valor);
  free(matriz);
  return;
}

matriz_t *matriz_obter_transposta( matriz_t *matriz)
{
  int nr_linhas = matriz->nr_linhas;
  int nr_colunas =  matriz->nr_colunas;
  matriz_t *matriz_transposta = matriz_criar(nr_colunas, nr_linhas);
  int i, j;
  printf("matriz transposta: \n");
  for(j = 0; j < nr_colunas; j++){
     for(i = 0; i < nr_linhas; i++){
	matriz_transposta->valor[j][i] = matriz->valor[i][j];
        printf("%d ", matriz_transposta->valor[j][i]);
     }
     printf("\n");
  }

  return matriz_transposta;
}

char **split ( const char *s1, const char *s2) {

    char **lista;
    char *aux = (char*)malloc(strlen(s1) + 1);
    strcpy(aux, s1);
    char *token_Ptr;
    int i = 0;

    lista = (char **) malloc (sizeof (char *));
    token_Ptr = strtok(aux, s2);
    lista[i] = token_Ptr;
    i++;
    while(token_Ptr != NULL)
    {
        lista = (char **)realloc(lista, sizeof(char*) * (i + 1));
        token_Ptr = strtok(NULL, s2);
        lista[i] = token_Ptr;
        i++;
    } 
    return lista;
}

matriz_t *matriz_incluir_valores(char *valores, matriz_t *matriz)
{
   char **tmp = split(valores,",");
   int i,j,counter;
   counter = 0;
   for (j = 0; j < matriz->nr_colunas; j++){
      for (i = 0; i < matriz->nr_linhas; i++){
          matriz->valor[i][j] = atoi(tmp[counter]);
          counter++;
      }
   }
   return matriz;
}

matriz_t *matriz_setar_valor_individual(int valor, matriz_t *matriz, int linha, int coluna)
{
   matriz->valor[linha][coluna] = valor;

   return matriz;
}

int matriz_pegar_valor_individual(matriz_t *matriz, int linha, int coluna)
{
   return matriz->valor[linha][coluna];
}


void imprime_matriz(matriz_t *matriz)
{
   int i, j;
   for (j = 0; j < matriz->nr_linhas; j++){
      for (i = 0; i < matriz->nr_colunas; i++){
		printf("%d ",matriz->valor[j][i]);
      }
      printf("\n");
   }
   return;
}
