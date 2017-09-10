#include <stdio.h>
#include <string.h>
#include <stack>

int ehNumero(char ch) {
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		return 1;
	return 0;
}
bool validaAlgarismosLinha(const char * palavra, int n) {
	int count;
	for (int i = 0; i < n; i++) {
		count = 0;
		while (palavra[i] != '\n'){
			if (ehNumero(palavra[i])) count++;
			i++;
		}
		if (count > 3) return false;
	}
	return true;
}

int soma_string(const char * string_entrada) {
	char delimitador = ',';
	char ch;
	int tamanho = strlen(string_entrada);

	if (string_entrada[tamanho-1] != '\n') return -1; //enter no final
	for (int i = 0; i < tamanho; i++)	{
		ch = string_entrada[i];
		if (!ehNumero(ch) && ch != delimitador && ch != '\n') return -1;
	}
	if(!validaAlgarismosLinha(string_entrada, tamanho)) return -1;

	return 0;
}