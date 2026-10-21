#ifndef STR_COUNT_H
#define STR_COUNT_H

#include <stddef.h>

/*Conta quantas palavras estão contidas em str*/
size_t str_wordcount(const char *str);

/*Conta quantas linhas não vazias estão contidas em str*/
size_t str_linecount(const char *str);

/*Conta a indicencia da substrings wrd dentro de str*/
size_t str_count(const char *str, const char *wrd);

#endif
