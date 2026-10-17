#ifndef STR_EDIT_H
#define STR_EDIT_H

char *str_lstrip(const char *texto);
char *str_rstrip(const char *texto);
char *str_strip(const char *texto);
char *str_zfill(const char *texto, int largura);
char *str_slice(const char *texto, int inicio, int fim);
char *str_replace(const char *texto, const char *antigo, const char *novo);

#endif