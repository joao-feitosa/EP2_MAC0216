#ifndef STR_TOKEN_H
#define STR_TOKEN_H

#include <stddef.h>

/*Retorna um vetor de strings com as palavras de str*/
char **str_splitwords(const char *string);

/*Retorna um vetor de strings com as linhas não vazias de str*/
char **str_splitlines(const char *str);

/*Libera um vetor de tokens
  Precisa receber o tamanho da lista de tokens, 
  Gerenciar o tamanho fica a cargo do usuário
*/
void str_free_tokens(char **tokens, size_t qtd);

#endif
