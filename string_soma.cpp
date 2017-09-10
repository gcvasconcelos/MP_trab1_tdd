#include <stdio.h>
#include <string.h>
#include <stack>

int ehNumero(char ch) {
	if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
		return 1;
	return 0;
}

int soma_string(const char * string_entrada) {
	std::stack<char> pilhaDelimitadores;
	char delimitador = ',';
	int n = strlen(string_entrada);

	if (string_entrada[n-1] != '\n') {
		return -1;
	}
	for (int i = 0; i < n; i++)	{
		char ch = string_entrada[i];
		if (!ehNumero(ch) && ch != delimitador && ch != '\n') return -1;
	}

	return 0;
}