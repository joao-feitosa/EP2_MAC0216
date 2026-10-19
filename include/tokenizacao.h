#include <stddef.h>

#ifndef TOKENIZACAO_H
#define TOKENIZACAO_H
 
/*Retorna um vetor de strings com as palavras de str*/
char **separa_palavras(const char *string);

/*Retorna um vetor de strings com as linhas não vazias de str*/
char **separa_linhas(const char *str);

/*Libera um vetor de tokens
  Precisa receber o tamanho da lista de tokens, 
  gerenciar o tamanho fica a cargo do usuário
*/
void free_tokens(char **tokens, size_t qtd);

#endif
