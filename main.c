#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main( void )
{
  matriz_t *m = matriz_criar( 3, 4 );
  printf("\nmatriz criada com sucesso!\n");
  m = matriz_incluir_valores("1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1", m);
  printf("valores incluidos com sucesso!\n");
  imprime_matriz(m);
  printf("matriz impressa com sucesso!\n"); 
  matriz_t *mt = matriz_obter_transposta(m);
  printf("transposta obtida com sucesso!\n");
  imprime_matriz(mt);
  printf("matriz impressa com sucesso!\n");
  matriz_destruir(m);
  printf("matriz destruida com sucesso!\n");
  exit( EXIT_SUCCESS );
}
