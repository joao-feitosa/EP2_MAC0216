#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "str_edit.h"

char *str_lstrip(const char *texto) {
    if (texto == NULL) return NULL;

    int len_inicial = strlen(texto);
    int inicio = 0;

    while (inicio < len_inicial && isspace(texto[inicio])) {
        inicio++;
    }

    int len = len_inicial - inicio;
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = texto[inicio + i];
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_rstrip(const char *texto) {
    if (texto == NULL) return NULL;

    int len_inicial = strlen(texto);
    int fim = len_inicial - 1;

    while (fim >= 0 && isspace(texto[fim])) {
        fim--;
    }

    int len = fim + 1;
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = texto[i];
    }

    resultado[len] = '\0';
    return resultado;
}