#include "tokenizacao.h"
#include "contagem.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void free_tokens(char **tokens, size_t qtd)
{
    size_t i;

    if (tokens == NULL)
        return;

    for (i = 0; i < qtd; ++i)
        free(tokens[i]);

    free(tokens);
}

char **separa_palavras(const char *str) {

    if (string == NULL)
    return NULL;

    char **tokens = malloc(sizeof(*tokens)*conta_palavras(str));

    if(tokens == NULL)
        return NULL;
        
    const char *pos = string;
    const char *inicio;

    while (*pos != '\0') {
        size_t tamanho;
        size_t qtd;

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

char **separa_linhas(const char *str)
{
    if (str == NULL)
        return NULL;

    char **tokens = malloc(sizeof(*tokens)*conta_linhas(str));

    if(tokens == NULL)
        return NULL;

    const char *inicio;
    const char *pos;
    const char *poscpy;

    pos = str;

    while (*pos != '\0') {
        size_t tamanho;
        size_t qtd;

        while (*pos != '\0' && isspace((unsigned char)*pos))
            pos++;

        if (*pos == '\0')
            break;

        inicio = pos;
        while (*pos != '\0' && !isspace((unsigned char)*pos))
            pos++;

        poscpy = pos;

        while (poscpy != '\0' && isspace(unsigned char)*pos)
            poscpy++;

        if (poscpy != '\0')
            tamanho = (size_t)(poscpy - inicio);
        else
            tamanho = (size_t)(pos - inicio);

        pos = poscpy;

        tokens[qtd] = malloc(tamanho + 1);

        strncpy(tokens[qtd], inicio, tamanho);
        tokens[qtd][tamanho] = '\0';
        qtd++;
    }

    if (qtd != NULL)
        *qtd = qtd;

    return tokens;
}
