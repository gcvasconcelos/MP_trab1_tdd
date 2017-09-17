#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** @file */ 

/**
 * @brief Verifica '\n' necessários na entrada.
 * @params string_entrada é a entrada a ser analisada.
 * @return true se é válido.
 */
bool valida_enter(const char *string_entrada) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  /** 
   * '\n' no final da string. 
   */
  if (entrada[strlen(string_entrada)-1] != '\n') return false;
  /**
   * Se entrada tiver delimitador customizado, este deve ser definido em uma linha separada. Ex:
   * entrada = "//[!]\n1\n"
   * temp == "]\n1\n"
   */
  if (entrada[0] == '/') {
    char *temp = strrchr(entrada, ']');  /**< resto da string a partir de ']'. */
    if (temp[1] != '\n') return false;
  }
  return true;
}
/**
 * @brief Conta o número de delimitadores na entrada.
 * @params string_entrada é a entrada a ser analisada.
 * @params delimitador é auto-explicativo.
 * @return número de delimitadores.
 */
int conta_delimitadores(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  int delimitadores = 0;
  char *temp = strpbrk(entrada, delimitador);  /**< primeira ocorrência do delimitador na string. */
  /**
   * Conta todas as ocorrências do delimitador na string.
   */
  while (temp != NULL){
    ++delimitadores;
    temp = strpbrk(temp+1, delimitador);
  }
  /**
   * Como o número de delimitadores é contado individualmente, o delimitador i.e. "!@#" contaria 3 (tamanho do delimitador) vezes a mais o número de delimitadores.
   * Por isso, o resultado é dividido pelo tamanho do delimitador.
   */
  return delimitadores /= strlen(delimitador);
}
/**
 * @brief Conta o número de números na string de entrada, de delimitador a delimitador.
 * @params string_entrada é a entrada a ser analisada.
 * @params delimitador é auto-explicativo.
 * @return número de números.
 */
int conta_numeros(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  int numeros = 0;
  char *temp = entrada;
  /**
   * Conta os numeros com base na quantidade de delimitadores.
   */
  while (strtok_r(temp, delimitador, &temp)) ++numeros;
  return numeros;
}
/**
 * @brief Verifica validez do delimitador na entrada.
 * @params string_entrada é a entrada a ser analisada.
 * @params delimitador é auto-explicativo.
 * @return true se válido.
 */
bool valida_delimitador(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  /**
   * Se não existe delimitador, é válido.
   */
  if (!(strpbrk(entrada, delimitador))) return true;
  int delimitadores = conta_delimitadores(entrada, delimitador);
  int numeros = conta_numeros(entrada, delimitador);
  /**
   * Como o número de números é contado a partir do numero de delimitadores, a entrada inválida i.e. "1,\n" contaria 2 números.
   * Por isso, deve-se decrementar 1 número da quantidade total, para corrigir esse erro.
   */
  if (entrada[strlen(entrada)-1] == '\n') {
    if (entrada[strlen(entrada)-2] == ',') --numeros;
  }
  /**
   * Retorna falso:
   * entrada = "1,,1\n"
   * delimitadores == 2
   * numeros == 2
   * Retorna verdadeiro:
   * entrada = "1,1\n"
   * delimitadores == 1
   * numeros == 2
   */
  if (!(delimitadores+1 == numeros)) return false;
  /**
   * Se a entrada tem um '-' e este não foi configurado como delimitador, significa que número é negativo, ou seja, inválido.
   */
  if (strpbrk(entrada, "-") && strcmp(delimitador, "-")) return false;
  return true;
}
/**
 * @brief Verifica validez do número.
 * @params string_entrada é a entrada a ser analisada.
 * @params delimitador é auto-explicativo.
 * @return true se válido.
 */
bool valida_numero(const char *string_entrada, char *delimitador) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  int numero = 0;
  char *linha = entrada;
  char *temp;
  /**
   * Verifica se existem até 3 números de linha em linha
   */
  while ((temp = strtok_r(linha, "\n", &linha))) {
    numero = conta_numeros(temp, delimitador);
    if (numero > 3) return false;
  }
  return true;
}
/**
 * @brief Verifica validez da entrada.
 * @params string_entrada é a entrada a ser analisada.
 * @params delimitador é auto-explicativo.
 * @return true se válido.
 */
bool valida_entrada(const char *string_entrada, char *delimitador) {
  /**
   * Se não segue as regras de validez, retorna falso.
   * @see valida_enter
   * @see valida_numero
   * @see valida_delimitador
   */
  if (!valida_enter(string_entrada)) return false;
  if (!valida_numero(string_entrada, delimitador)) return false;
  if (!valida_delimitador(string_entrada, delimitador)) return false;
  return true;
}
/**
 * @brief Retorna o delimitador a ser usado na entrada
 * @params string_entrada é a entrada a ser analisada
 * @return delimitador (default ',' ou o definido na entrada) ou NULL
 */
char *retorna_delimitador(const char *string_entrada) {
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */

  unsigned int comeco = strspn(entrada, "//[");  //**< índice de onde a entrada comeca a ficar diferente do formato "//[", ou seja, 3. Se não acha o formato, retorna entre 0 e 2. */
  unsigned int fim = strcspn(entrada, "]");  //**< índice de onde a entrada fica igual ao char "]". Se não acha o char, é igual ao tamanho da string */
  /**
   * Se o começo é igual a 3 (entrada segue o formato "//[") e o fim não é igual tamanho da entrada (o colchete é fechado), o usuário quer definir um novo delimitador.
   * Se o começo é igual a 0 (entrada com delimitador padrão) e o fim é igual ao tamanho da string (não acha colchete fechado).
   * Se nenhum desses, entrada é inválida.
   */
  if (comeco == 3 && fim != strlen(entrada)) {
    char *delimitador = (char *) malloc(fim-comeco);
    /**
     * Captura delimitador entre os colchetes da string de entrada.
     */
    sscanf(entrada, "//[%s\n%*s", delimitador);
    delimitador = strtok_r(delimitador, "]", &delimitador);
    return delimitador;
  } else if (comeco == 0 && fim == strlen(entrada)) {
    /**
     * Verifica se entrada contem apenas o delimitador default
     */
    if (strspn(entrada, "01234556789\n,") == strlen(entrada)) {
      return strdup(",");
    }
  } 
  return NULL;
}
/**
 * @brief Recebe uma string, valida-a e faz a operação de soma
 * @params string_entrada é a entrada a ser analisada
 * @return resultado da soma
 */
int soma_string(const char *string_entrada) {
  char *delimitador_atual;
  /**
   * Checa se delimitador é o default ou se foi corretamente definido
   */
  if (!(delimitador_atual = retorna_delimitador(string_entrada))) return -1;
  /**
   * Checa se a entrada é valida
   */
  if (!valida_entrada(string_entrada, delimitador_atual)) return -1;
  char *entrada = strdup(string_entrada);  /**< copia entrada para string que pode ser manipulada. */
  char *temp;
  int resultado = 0;
  /**
   * Captura tudo que não seja "[]/\n" e delimitador da entrada, ou seja, os números.
   * Os números estarão como string, então, são convertidos para inteiro e são somados.
   */
  while ((temp = strtok_r(entrada, 
                          strcat(delimitador_atual, "[]/\n"), 
                          &entrada))) {
    if (atoi(temp) <= 1000) resultado += atoi(temp);
  }
  return resultado;
}