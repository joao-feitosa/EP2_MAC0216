#include <stddef.h>

#ifndef BUSCA_H
#define BUSCA_H

/*Conta quantas palavras tem em str*/
size_t conta_palavras(const char *str);
 
/*Conta quantas linhas não vazias tem em str*/
size_t conta_linhas(const char *str);

/*Conta quantas ocorrencias de wrd existem sem sobreposição em str*/
size_t conta_ocorrencias(const char *str, const char *wrd);

#endif
