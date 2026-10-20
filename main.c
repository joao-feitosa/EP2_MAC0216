#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contagem.h"
#include "str_case.h"
#include "str_edit.h"
#include "tokenizacao.h"

int main(void) {
    char *resultado;
    char **tokens;

    assert(conta_palavras("palavra word") == 2);
    assert(conta_palavras("") == 0);
    assert(conta_palavras(NULL) == 0);
    assert(conta_linhas("  palavra  \n  \n  word  ") == 2);
    assert(conta_linhas("\n\n\n") == 0);
    assert(conta_ocorrencias("abaca", "aba") == 1);

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

    tokens = separa_palavras("   varias, \n \n muitas, \n\n\n palavras  \n\n");
    assert(tokens != NULL);
    assert(strcmp(tokens[0], "varias,") == 0);
    assert(strcmp(tokens[1], "muitas,") == 0);
    assert(strcmp(tokens[2], "palavras") == 0);
    free_tokens(tokens, 3);

    tokens = separa_linhas("   varias,  muitas, \n\n\n palavras  \n\n");
    assert(tokens != NULL);
    assert(strcmp(tokens[0], "varias,  muitas,") == 0);
    assert(strcmp(tokens[1], "palavras") == 0);
    free_tokens(tokens, 2);

    printf("testes concluidos\n");
    return 0;
}