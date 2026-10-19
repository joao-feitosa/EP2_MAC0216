#include "contagem.h"

#include <string.h>

#include <ctype.h>
#include <stddef.h>

size_t conta_palavras(const char *str) {
    if (str == NULL)
        return 0;

    size_t count = 0;
    int in_word = 0;

    while (*str != '\0') {
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }

        str++;
    }

    return count;
}

size_t conta_linhas(const char *str) {
    if (str == NULL)
        return 0;

    size_t count = 0;
    int in_line = 0;

    while (*str != '\0') {
        if (!isspace((unsigned char)*str) && !in_line) {
            count++;
            in_line = 1;
        } elif (*str == '\n'){
            in_line = 0;
        }

        str++;
    }

    return count;
}