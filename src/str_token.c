#include "str_token.h"
#include "str_count.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

void str_free_tokens(char **tokens, size_t qtd) {
    if (tokens == NULL) return;

    for (size_t i = 0; i < qtd; ++i)
        free(tokens[i]);

    free(tokens);
}

char **str_splitwords(const char *str) {

    if (str == NULL) return NULL;

    char **tokens = malloc(sizeof(*tokens) * str_wordcount(str));
    if (tokens == NULL) return NULL;
        
    const char *pos = str;
    const char *inicio;
    size_t qtd = 0;

    while (*pos != '\0') {
        size_t tamanho;

        while (*pos != '\0' && isspace((unsigned char)*pos))
            pos++;

        if (*pos == '\0')
            break;

        inicio = pos;
        while (*pos != '\0' && !isspace((unsigned char)*pos))
            pos++;

        tamanho = (size_t)(pos - inicio);

        tokens[qtd] = malloc(tamanho + 1);

        strncpy(tokens[qtd], inicio, tamanho);
        tokens[qtd][tamanho] = '\0';
        qtd++;
    }

    return tokens;
}

char **str_splitlines(const char *str) {
    if (str == NULL) return NULL;

    char **tokens = malloc(sizeof(*tokens) * str_linecount(str));
    if(tokens == NULL) return NULL;

    const char *inicio;
    const char *pos = str;
    const char *poscpy;
    size_t qtd = 0;

    while (*pos != '\0') {
        size_t tamanho;

        while (*pos != '\0' && isspace((unsigned char)*pos)) {
            pos++;
        }

        if (*pos == '\0') break;
        inicio = pos;

        while (*pos != '\0' && *pos != '\n') {
            pos++;

        }

        poscpy = pos;
        if (*poscpy == '\n') {
            poscpy++;
        }

        tamanho = (size_t)(pos - inicio);
        tokens[qtd] = malloc(tamanho + 1);

        if (tokens[qtd] != NULL) {
            strncpy(tokens[qtd], inicio, tamanho);
            tokens[qtd][tamanho] = '\0';
            qtd++;
        }

        pos = poscpy;
    }

    return tokens;
}