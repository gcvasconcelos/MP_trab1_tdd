#include <stdio.h>
#include <string.h>
#include <stack>

bool eh_numero(char ch) {
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		return true;
	return false;
}
int conta_numeros(const char *entrada, int tamanho){
	int j = 1, count = 0;
	for (int i = 0; i < tamanho; ++i) {
		if (eh_numero(entrada[i])) {
			while (eh_numero(entrada[i+j])) {
				++i;
			}
			++count;
		}
	}
	return count;
}
int conta_delimitadores(const char *entrada, int tamanho, char delimitador) {
	int count = 0;
	for (int i = 0; i < tamanho; ++i) {
		if (entrada[i] == delimitador) ++count;
	}
	return count;
}
bool valida_enter_final(const char *entrada, int tamanho){
	if (entrada[tamanho-1] != '\n') return false; //enter no final
	return true;
}
bool valida_algarismos_linha(const char *entrada, int tamanho) {
	int count;
	for (int i = 0; i < tamanho; ++i) {
		count = 0;
		while (entrada[i] != '\n') {
			if (eh_numero(entrada[i])) ++count;
			++i;
		}
		if (count > 3) return false;
	}
	return true;
}
bool valida_delimitador(const char *entrada, int tamanho, char delimitador) {
	char ch;
	for (int i = 0; i < tamanho; ++i) {
		ch = entrada[i];
		if (!eh_numero(ch) && ch != delimitador && ch != '\n') return false;
	}

	bool vazia = conta_delimitadores(entrada, tamanho, delimitador) + conta_numeros(entrada, tamanho) == 0;
	bool num_delimitador_valido = conta_delimitadores(entrada, tamanho, delimitador) + 1 == conta_numeros(entrada, tamanho);

	if (vazia || num_delimitador_valido)	return true;
	return false;
}
bool valida_numero(const char *entrada, int tamanho) {
	for (int i = 0; i < tamanho; ++i)
		if (entrada[i] == '-') return false;
	return true;
}


int soma_string(const char *string_entrada) {
	char delimitador = ',';
	int tamanho = strlen(string_entrada);

	if (!valida_enter_final(string_entrada, tamanho)) return -1;
	if (!valida_algarismos_linha(string_entrada, tamanho)) return -1;
	if (!valida_delimitador(string_entrada, tamanho, delimitador)) return -1;
	if (!valida_numero(string_entrada, tamanho)) return -1;

	return 0;
}