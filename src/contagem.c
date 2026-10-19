#include "contagem.h"

#include <string.h>

#include <ctype.h>
#include <stddef.h>

size_t conta_palavras(const char *str) {
    if (str == NULL)
        return 0;

    size_t count = 0;
    int in_word = 0;
    char *pos = str;

    while (*pos != '\0') {
        if (isspace((unsigned char)*pos)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }

        pos++;
    }

    return count;
}

size_t conta_linhas(const char *str) {
    if (str == NULL)
        return 0;

    size_t count = 0;
    int in_line = 0;
    char *pos = str;

    while (*pos != '\0') {
        if (!isspace((unsigned char)*pos) && !in_line) {
            count++;
            in_line = 1;
        } elif (*pos == '\n'){
            in_line = 0;
        }

        pos++;
    }

    return count;
}

size_t conta_ocorrencias(const char *str, const char *wrd) {
    if (str = NULL)
        return 0;
    
    size_t count = 0;
    char *pos = str;
    size_t size = strlen(wrd);

    while () {

        pos = strstr(pos, wrd);
        if(pos == NULL)
            break;
        
        pos += size;
        count++;

    }
    
    return count;
}