#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <list>
#include <algorithm>
#include <iostream>


bool valida_entrada(const char *string_entrada, char *delimitador);
int conta_numeros(const char *string_entrada, char *delimitador);
char *retorna_delimitador(const char *string_entrada) {
  char *entrada = strdup(string_entrada); 
  unsigned int comeco, fim;
  comeco = strspn(entrada, "//[");
  fim = strcspn(entrada, "]");
  if (comeco == 3 && fim != strlen(entrada)) {
    char *delimitador = (char *) malloc(fim-comeco);
    sscanf(entrada, "//[%s\n%*s", delimitador);
    delimitador = strtok_r(delimitador, "]", &delimitador);
    printf("###delimitador-->%s<--\n", delimitador);
    return delimitador;
  } else if (comeco == 0 && fim == strlen(entrada)) {
    if (strspn(entrada, "01234556789\n,") == strlen(entrada)) return strdup(",");
  } 
  return NULL;
}

int soma_string(const char *string_entrada) {
  char *delimitador_atual;
  if (!(delimitador_atual = retorna_delimitador(string_entrada))) return -1;
  if (!valida_entrada(string_entrada, delimitador_atual)) return -1;
  char *entrada = strdup(string_entrada); 
  char *temp;
  int resultado = 0;
  while ((temp = strtok_r(entrada, strcat(delimitador_atual, "[]/\n"), &entrada))) {
    if (atoi(temp) <= 1000) resultado += atoi(temp);
  }
  return resultado;
}

bool valida_enter_final(const char *string_entrada, int tamanho) {
  char *entrada = strdup(string_entrada); 
  if (entrada[tamanho-1] != '\n') return false; //enter no final
  if (entrada[0] == '/') {
    char *temp = strrchr(entrada, ']');
    if (temp[1] != '\n') return false;
  }
  return true;
}
int conta_delimitadores(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada); 
  char *temp;
  int delimitadores = 0;
  temp = strpbrk(entrada, delimitador);
  while (temp != NULL){
    ++delimitadores;
    temp = strpbrk(temp+1, delimitador);
  }
  return delimitadores;
}
int conta_numeros(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada); 
  int numeros = 0;
  char *temp = entrada;
  if (entrada[strlen(entrada)-1] == '\n')
    if (entrada[strlen(entrada)-2] == ',') --numeros;
  while (strtok_r(temp, delimitador, &temp)) ++numeros;
  return numeros;
}
bool valida_delimitador(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);
  if (strpbrk(entrada, delimitador)) {  //se nao existem delimitadores na entrada
    int delimitadores = conta_delimitadores(entrada, delimitador);
    int numeros = conta_numeros(entrada, delimitador);
    delimitadores /= strlen(delimitador);
    if (!(delimitadores+1 == numeros)) return false;
  }
  return true;
}
bool valida_numero(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);
  int numero = 0;
  char *linha = entrada;
  char *temp;
  while ((temp = strtok_r(linha, "\n", &linha))) {
    numero = conta_numeros(temp, delimitador);
    if (numero > 3) return false;
  }
  return true;
}
bool valida_numero_positivo(const char *string_entrada, char * delimitador) {
  char *entrada = strdup(string_entrada); 
  if (strpbrk(entrada, "-") && strcmp(delimitador, "-")) return false;
  return true;
}
bool valida_entrada(const char *string_entrada, char *delimitador) {
  int tamanho = strlen(string_entrada);
  if (!valida_enter_final(string_entrada, tamanho)) return false; //check
  if (!valida_numero(string_entrada, delimitador)) return false;
  if (!valida_delimitador(string_entrada, delimitador)) return false;
  if (!valida_numero_positivo(string_entrada, delimitador)) return false;
  return true;
}