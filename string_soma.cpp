#include <stdio.h>
#include <string.h>

int soma_string(const char * string_entrada) {
	int n = strlen(string_entrada);
	if (string_entrada[n-1] != '\n') {
		return -1;
	}

	return 0;
}