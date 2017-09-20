#include <stdio.h>
#include <stdlib.h>
#include "headers/string_soma.hpp"

/** @file */ 
/**
 * Arquivo que lê uma string de entrada padrão, calcula a soma dos numeros positivos menores ou iguais a 1000 nessa string por meio da função soma_string() e printa na tela o resultado da função. Se -1, a entrada foi inválida.
 */

int main() {
  char entrada[100], ch;
  unsigned int i = 0;
  int resultado;
  while ((ch = getchar()) != EOF) {
    entrada[i] = ch;
    ++i;
  }
  entrada[i] = '\0';
  resultado = soma_string(entrada);
  printf("%d\n", resultado);
	return 0;
}