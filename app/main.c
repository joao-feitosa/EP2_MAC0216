#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "str_case.h"
#include "str_edit.h"
#include "str_count.h"
#include "str_token.h"

int main() {
    const char *str_teste = "Fazem-se COISAS nesta cidade.";

    char *maiuscula = str_upper(str_teste);
    char *minuscula = str_lower(str_teste);
    char *capitalizado = str_capitalize(str_teste);
    char *titulo = str_title(str_teste);

    printf("Original: %s\n", str_teste);
    printf("Maiúsculas: %s\n", maiuscula);
    printf("Minusculas: %s\n", minuscula);
    printf("Capitalizado: %s\n", capitalizado);
    printf("Título: %s\n", titulo);

    free(maiuscula);
    free(minuscula);
    free(capitalizado);
    free(titulo);

    const char *str_teste_2 = "     JAIR BOLSONARO 22  ";

    char *tira_esquerda = str_lstrip(str_teste_2);
    char *tira_direita = str_rstrip(str_teste_2);
    char *tira_tudo = str_strip(str_teste_2);

    printf("Original: %s, NÃO ELEITO\n", str_teste_2);
    printf("Lstrip: %s, NÃO ELEITO\n", tira_esquerda);
    printf("Rstrip: %s, NÃO ELEITO\n", tira_direita);
    printf("Limpo: %s, NÃO ELEITO\n", tira_tudo);

    free(tira_esquerda);
    free(tira_direita);
    free(tira_tudo);

    const char *str_teste_3 = "012345678910";

    char *slice1 = str_slice(str_teste_3, 0, 5);
    char *slice2 = str_slice(str_teste_3, 0, 11);
    char *slice3 = str_slice(str_teste_3, 11, 11);
    char *slice4 = str_slice(str_teste_3, 0, 200);
    char *slice5 = str_slice(str_teste_3, -8, -1);
    char *slice6 = str_slice(str_teste_3, -200, 5);

    printf("Originl: %s\n", str_teste_3);
    printf("Slice 1: %s\n", slice1);
    printf("Slice 2: %s\n", slice2);
    printf("Slice 3: %s\n", slice3);
    printf("Slice 4: %s\n", slice4);
    printf("Slice 5: %s\n", slice5);
    printf("Slice 6: %s\n", slice6);

    free(slice1);
    free(slice2);
    free(slice3);
    free(slice4);
    free(slice5);
    free(slice6);

    const char *str_teste_4 = "O leão, a feiticeira e o guarda-roupa";

    char *replace1 = str_replace(str_teste_4, "leão", " gatinho");
    char *replace2 = str_replace(str_teste_4, "O", " o");
    char *replace3 = str_replace(str_teste_4, "guarda_roupa", "armário");
    char *replace4 = str_replace(str_teste_4, "a", "");

    printf("Original: %s\n", str_teste_4);
    printf("Replace 1: %s\n", replace1);
    printf("Replace 2: %s\n", replace2);
    printf("Replace 3: %s\n", replace3);
    printf("Replace 4: %s\n", replace4);

    free(replace1);
    free(replace2);
    free(replace3);
    free(replace4);

    const char *str_teste_5 = 
        "O rato roeu a roupa do rei de Roma.\n"
        "O rei de Roma ficou furioso e mandou pegar o rato.\n"
        "\n"
        "No final, o rato fugiu para a cidade de Roma!";
    
    size_t n_palavras = str_wordcount(str_teste_5);
    size_t n_linhas = str_linecount(str_teste_5);
    size_t n_roma = str_count(str_teste_5, "Roma");
    
    printf("Texto: '%s'\n", str_teste_5);
    printf("Contagem de palavras: %zu\n", n_palavras);
    printf("Contagem de linhas nao vazias: %zu\n", n_linhas);
    printf("Ocorrencias da palavra 'Roma': %zu\n\n", n_roma);

    const char *str_teste_6 = 
        "Hello, there \n"
        "The angel from my nightmare, \n"
        "The shadow in the background of the morgue.";

    size_t n_words = str_wordcount(str_teste_6);
    char **palavras = str_splitwords(str_teste_6);

    printf("Palavras separadas:\n");
    if (palavras != NULL) {
        for (size_t i = 0; i < n_words; i++) {
            printf("  [%zu] %s\n", i, palavras[i]);
        }
        
        str_free_tokens(palavras, n_words);
    }

    size_t n_lines = str_linecount(str_teste_6);
    char **linhas = str_splitlines(str_teste_6);

    printf("\nLinhas separadas:\n");
    if (linhas != NULL) {
        for (size_t i = 0; i < n_lines; i++) {
            printf("  [%zu] %s\n", i, linhas[i]);
        }

        str_free_tokens(linhas, n_lines);
    }

    return 0;
}