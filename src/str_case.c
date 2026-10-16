#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "str_case.h"

char *str_upper(const char *texto) {
    if (texto == NULL) return NULL;

    int len = strlen(texto);
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = toupper(texto[i]);
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_lower(const char *texto) {
    if (texto == NULL) return NULL;

    int len = strlen(texto);
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = tolower(texto[i]);
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_capitalize(const char *texto) {
    if (texto == NULL) return NULL;

    int len = strlen(texto);
    char *resultado = malloc(len + 1);

    if (len > 0) {
        resultado[0] = toupper(texto[0]);

        for (int i = 1; i < len; i++) {
            resultado[i] = tolower(texto[i]);
        }
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_title(const char *texto) {
    if (texto == NULL) return NULL;

    int len = strlen(texto);
    char *resultado = malloc(len + 1);
    bool nova_palavra = true;

    for (int i = 0; i < len; i++) {
        if (isspace(texto[i])) {
            resultado[i] = texto[i];
            nova_palavra = true;
        } else {
            if (nova_palavra == true) {
                resultado[i] = toupper(texto[i]);
                nova_palavra = false;
            } else {
                resultado[i] = tolower(texto[i]);
            }
        }
    }
    
    resultado[len] = '\0';
    return resultado;
}