#include "str_count.h"

#include <string.h>
#include <ctype.h>
#include <stddef.h>

size_t str_wordcount(const char *str) {
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

size_t str_linecount(const char *str) {
    if (str == NULL)
        return 0;

    size_t count = 0;
    int in_line = 0;

    while (*str != '\0') {
        if (!isspace((unsigned char)*str) && !in_line) {
            count++;
            in_line = 1;
        } else if (*str == '\n') {
            in_line = 0;
        }

        str++;
    }

    return count;
}

size_t str_count(const char *str, const char *wrd) {
    if (str == NULL || wrd == NULL)
        return 0;
    
    size_t size = strlen(wrd);

    if (size == 0) {
        return 0;
    }

    size_t count = 0;
    const char *pos = str;

    while (1) {

        pos = strstr(pos, wrd);
        if(pos == NULL)
            break;
        
        pos += size;
        count++;

    }
    
    return count;
}