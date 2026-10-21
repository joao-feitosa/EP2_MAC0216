#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "str_case.h"
#include "str_edit.h"
#include "str_count.h"
#include "str_token.h"

int main(void) {
    char cep[] = "   05508-220    ";
    char lugar[] = "universidade de são paulo";

    /*Conversão de case pra padrão título*/
    char *lugar_title = str_title(lugar);

    /*Elimina espaços*/
    char *cep_limpo = str_strip(cep);

    /*Remove hífen do CEP*/
    char *cep_sem_hifen = str_replace(cep_limpo, "-", "");

    if (strlen(cep_sem_hifen) == 8) {

        /*Fatia os últimos 3 números do CEP*/
        char *final_cep = str_slice(cep_sem_hifen, 5, 8);

        printf("Lugar: %s\n", lugar_title);
        printf("CEP Final: %s\n", final_cep);

        free(final_cep);
    }

    free(lugar_title);
    free(cep_limpo);
    free(cep_sem_hifen);
}