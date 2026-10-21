#ifndef STR_EDIT_H
#define STR_EDIT_H

/*Elimina espaços vazios à esquerda de texto*/
char *str_lstrip(const char *texto);

/*Elimina espaços vazios à direita de texto*/
char *str_rstrip(const char *texto);

/*Elimina espaços vazios à esquerda e à direita de texto*/
char *str_strip(const char *texto);

/*Fatia texto a partir dos índice inicio e fim. Aceita índices negativos.*/
char *str_slice(const char *texto, int inicio, int fim);

/*Substitui uma substring antigo por uma novo dentro de texto*/
char *str_replace(const char *texto, const char *antigo, const char *novo);

#endif