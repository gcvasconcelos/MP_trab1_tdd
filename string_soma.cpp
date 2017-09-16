#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

bool valida_enter_final(char *entrada, int tamanho);
bool valida_numero(char *entrada, char *delimitador);
bool valida_delimitador(char *entrada, char *delimitador);
bool valida_numero_positivo(const char *string_entrada);
bool valida_tamanho_numero(char *entrada, char *delimitador);
bool valida_entrada(const char *string_entrada, char *delimitador);

int soma_string(const char *string_entrada) {
  char delimitador[] = ",";
  if (!valida_entrada(string_entrada, delimitador)) return -1; 
	return 0;
}

bool valida_enter_final(const char *string_entrada, int tamanho) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);
  if (entrada[tamanho-1] != '\n') return false; //enter no final
  return true;
}
int conta_delimitadores(const char *string_entrada, char *delimitador) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);
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
  char entrada[100]; 
  strcpy(entrada, string_entrada);
  int numeros = 0;
  char *temp = entrada;
  if (entrada[strlen(entrada)-1] == '\n')
    if (entrada[strlen(entrada)-2] == ',') --numeros;
  while (strtok_r(temp, delimitador, &temp)) {
    ++numeros;
  }
  return numeros;
}
bool valida_delimitador(const char *string_entrada, char *delimitador) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);  
  if (strpbrk(entrada, delimitador)) {  //se nao existem delimitadores na entrada
    int delimitadores = conta_delimitadores(entrada, delimitador);
    int numeros = conta_numeros(entrada, delimitador);
    if (!(delimitadores+1 == numeros)) return false;
  }
  return true;
}
bool valida_numero(const char *string_entrada, char *delimitador) {
  char entrada[100];
  int numero = 0;
  strcpy(entrada, string_entrada);
  char *linha = entrada;
  char *temp;
  while ((temp = strtok_r(linha, "\n", &linha))) {
    numero = conta_numeros(temp, delimitador);
    if (numero > 3) return false;
  }
  return true;
}
bool valida_numero_positivo(const char *string_entrada) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);
  if (strpbrk(entrada, "-")) return false;
  return true;
}
bool valida_tamanho_numero(const char *string_entrada, char *delimitador) {
  char entrada[100]; 
  strcpy(entrada, string_entrada);
  char *temp = entrada;
  char *buff;
  while ((buff = strtok_r(temp, delimitador, &temp))) {
    if (atoi(buff) > 1000) return false;
  }
  return true;
}
bool valida_entrada(const char *string_entrada, char *delimitador) {
  int tamanho = strlen(string_entrada);
  
  if (!valida_enter_final(string_entrada, tamanho)) return false; //check
  if (!valida_numero(string_entrada, delimitador)) return false;
  if (!valida_delimitador(string_entrada, delimitador)) return false;
  if (!valida_numero_positivo(string_entrada)) return false;
  if (!valida_tamanho_numero(string_entrada, delimitador)) return false;
  return true;
}