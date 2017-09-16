#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

bool valida_enter_final(char *entrada, int tamanho){
	if (entrada[tamanho-1] != '\n') return false; //enter no final
	return true;
}
bool valida_numero(char *entrada, char *delimitador) {
  char *linha, *cols;
  int count;
  linha = strtok(entrada, "\n");
  while (linha != NULL) {
    count = 0;
    cols = strpbrk(linha, delimitador);
    ++count;
    while (cols != NULL) {
      ++count;
      cols = strpbrk(cols+1, delimitador);  //proximo numero
    }
    if (count > 3) return false;
    linha = strtok(NULL, "\n");  //proxima linha
  }
  return true;
}
bool valida_delimitador(char *entrada, char *delimitador) {
  if (strpbrk(entrada, delimitador)) {  //se nao existem delimitadores na entrada
    int numeros = 0, delimitadores;
    char *temp;
    temp = strpbrk(entrada, delimitador);
    while (temp != NULL){
      ++delimitadores;
      temp = strpbrk(temp+1, delimitador);
    }
    temp = strtok(entrada, delimitador);
    while (temp != NULL) {
      ++numeros;
      temp = strtok(NULL, delimitador);
    }
    if (!(delimitadores+1 == numeros)) return false;
  }
  return true;
}
// bool valida_numero_positivo(char *entrada) {
//   printf("\nENTRADAFUNC->%s<-\n", entrada);
//   if (strpbrk(entrada, "-")) return false;
//   return true;
// }
bool valida_numero_positivo(const char *string_entrada) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);
  if (strpbrk(entrada, "-")) return false;
  return true;
}
bool valida_tamanho_numero(char *entrada, char *delimitador) {
  char *temp;
  temp = strtok(entrada, strcat(delimitador, "\n"));
  while (temp != NULL) {
    if (atoi(temp) > 1000) return false;
    temp = strtok(NULL, delimitador);
  }
  return true;
}

int soma_string(const char *string_entrada) {
  char delimitador[] = ",";
  char entrada[100]; 
  int tamanho = strlen(string_entrada);
  strcpy(entrada, string_entrada);
	if (!valida_enter_final(entrada, tamanho)) return -1; //check
  if (!valida_numero(entrada, delimitador)) return -1;
  if (!valida_delimitador(entrada, delimitador)) return -1;
  if (!valida_numero_positivo(string_entrada)) return -1;
  if (!valida_tamanho_numero(entrada, delimitador)) return -1;

	return 0;
}