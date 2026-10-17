#include <stdio.h>
#include <stdlib.h>
#include "str_case.h"
#include "str_edit.h"

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

    const char *str_teste_2 = "  RENAN SANTOS 14  ";

    char *tira_esquerda = str_lstrip(str_teste_2);
    char *tira_direita = str_rstrip(str_teste_2);
    char *tira_tudo = str_rstrip(tira_esquerda);

    printf("Original: %s, NÃO ELEITO\n", str_teste_2);
    printf("Lstrip: %s, NÃO ELEITO\n", tira_esquerda);
    printf("Rstrip: %s, NÃO ELEITO\n", tira_direita);
    printf("Limpo: %s, NÃO ELEITO\n", tira_tudo);

    return 0;
}