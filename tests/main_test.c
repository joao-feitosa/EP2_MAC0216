#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str_count.h"
#include "str_case.h"
#include "str_edit.h"
#include "str_token.h"

int main(void) {
    char *resultado;
    char **tokens;

    assert(str_wordcount("palavra word") == 2);
    assert(str_wordcount("") == 0);
    assert(str_wordcount(NULL) == 0);
    assert(str_linecount("  palavra  \n  \n  word  ") == 2);
    assert(str_linecount("\n\n\n") == 0);
    assert(str_count("abaca", "aba") == 1);

    resultado = str_upper("palavra?");
    assert(resultado != NULL && strcmp(resultado, "PALAVRA?") == 0);
    free(resultado);

    resultado = str_lower("PALAVRA!");
    assert(resultado != NULL && strcmp(resultado, "palavra!") == 0);
    free(resultado);

    resultado = str_capitalize("palavra");
    assert(resultado != NULL && strcmp(resultado, "Palavra") == 0);
    free(resultado);

    resultado = str_title("varias palavras");
    assert(resultado != NULL && strcmp(resultado, "Varias Palavras") == 0);
    free(resultado);

    resultado = str_lstrip("    palavra    ");
    assert(resultado != NULL && strcmp(resultado, "palavra    ") == 0);
    free(resultado);

    resultado = str_rstrip("    palavra    ");
    assert(resultado != NULL && strcmp(resultado, "    palavra") == 0);
    free(resultado);

    resultado = str_strip("    palavra    ");
    assert(resultado != NULL && strcmp(resultado, "palavra") == 0);
    free(resultado);

    resultado = str_slice("palavra", 1, 4);
    assert(resultado != NULL && strcmp(resultado, "ala") == 0);
    free(resultado);

    resultado = str_replace("palavras", "avr", "h");
    assert(resultado != NULL && strcmp(resultado, "palhas") == 0);
    free(resultado);

    tokens = str_splitwords("   varias, \n \n muitas, \n\n\n palavras  \n\n");
    assert(tokens != NULL);
    assert(strcmp(tokens[0], "varias,") == 0);
    assert(strcmp(tokens[1], "muitas,") == 0);
    assert(strcmp(tokens[2], "palavras") == 0);
    str_free_tokens(tokens, 3);

    tokens = str_splitlines("varias,  muitas,\n\n\npalavras\n\n");
    assert(tokens != NULL);
    assert(strcmp(tokens[0], "varias,  muitas,") == 0);
    assert(strcmp(tokens[1], "palavras") == 0);
    str_free_tokens(tokens, 2);

    printf("testes concluidos\n");
    return 0;
}