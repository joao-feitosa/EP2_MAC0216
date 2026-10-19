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

char *str_strip(const char *texto) {
    if (texto == NULL) return NULL;

    int len_inicial = strlen(texto);
    int inicio = 0;
    int fim = len_inicial - 1;

    while (inicio < len_inicial && isspace(texto[inicio])) {
        inicio++;
    }

    while (fim >= inicio && isspace(texto[fim])) {
        fim--;
    }

    int len = fim - inicio + 1;
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = texto[inicio + i];
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_slice(const char *texto, int inicio, int fim) {
    if (texto == NULL) return NULL;

    int len_inicial = strlen(texto);

    if (inicio < 0) inicio = len_inicial + inicio;
    if (fim < 0) fim = len_inicial + fim;

    if (inicio < 0) inicio = 0;
    if (inicio > len_inicial) inicio = len_inicial;
    if (fim < 0) fim = 0;
    if (fim > len_inicial) fim = len_inicial;

    int len = fim - inicio;
    if (len < 0) len = 0;
    char *resultado = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        resultado[i] = texto[inicio + i];
    }

    resultado[len] = '\0';
    return resultado;
}

char *str_replace(const char *texto, const char *antigo, const char *novo) {
    if (texto == NULL || antigo == NULL || novo == NULL) {
        return NULL;
    }

    int len_texto = strlen(texto);
    int len_antigo = strlen(antigo);
    int len_novo = strlen(novo);

    char *resultado = malloc(len_texto + 1);

    if (len_antigo == 0) {
        strcpy(resultado, texto);
        return resultado;
    }

    int contador = 0;
    const char *ponteiro_busca = texto;

    while (ponteiro_busca != NULL) {
        ponteiro_busca = strstr(ponteiro_busca, antigo);

        if (ponteiro_busca == NULL) break;

        contador++;
        ponteiro_busca += len_antigo;
    }

    if (contador == 0) {
        strcpy(resultado, texto);
        return resultado;
    }

    int len_final = len_texto + (contador * (len_novo - len_antigo));
    resultado = realloc(resultado, len_final + 1);

    const char *posicao_texto = texto;
    int posicao_resultado = 0;

    while (*posicao_texto != '\0') {
        if (strncmp(posicao_texto, antigo, len_antigo) == 0) {
            for (int i = 0; i < len_novo; i++) {
                resultado[posicao_resultado] = novo[i];
                posicao_resultado++;
            }

            posicao_texto += len_antigo;

        } else {
            resultado[posicao_resultado] = *posicao_texto;
            posicao_resultado++;
            posicao_texto++;
        }
    }

    resultado[len_final] = '\0';
    return resultado;
}