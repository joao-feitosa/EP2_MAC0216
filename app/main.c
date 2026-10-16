#include <stdio.h>
#include <stdlib.h>
#include "str_case.h"

int main() {
    const char *string_teste = "Fazem-se COISAS nesta cidade.";

    char *maiuscula = str_upper(string_teste);
    char *minuscula = str_lower(string_teste);
    char *capitalizado = str_capitalize(string_teste);
    char *titulo = str_title(string_teste);

    printf("Original: %s\n", string_teste);
    printf("Maiúsculas: %s\n", maiuscula);
    printf("Minusculas: %s\n", minuscula);
    printf("Capitalizado: %s\n", capitalizado);
    printf("Título: %s\n", titulo);

    free(maiuscula);
    free(minuscula);
    free(capitalizado);
    free(titulo);

    return 0;
}