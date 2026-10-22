# Biblioteca str_plus

Biblioteca em C para manipulação, quantificação e tokenização de strings

## Pré-requisitos

- Compilador GCC
- GNU Make
- Bibliotecas-padrão do C: 
    - string.h
    - stdlib.h
    - stdint.h
    - ctype.h
    - stddef.h

## Estrutura do Projeto

- `include/`: Arquivos de cabeçalho (`.h`) contendo a API pública da biblioteca.
- `src/`: Arquivos de implementação (`.c`) dos módulos.
- `app/`: Aplicação cliente (`main.c`) que consome a biblioteca.
- `tests/`: Coleção de testes automatizados para todas as funções públicas.

## Módulos e Funções

A biblioteca `str_plus` é composta por 4 módulos e 15 funções ao todo

**Aviso de Gerenciamento de Memória:** As funções desta biblioteca (exceto as de contagem) alocam memória dinamicamente para preservar as strings originais. É responsabilidade da aplicação cliente liberar a memória retornada utilizando `free()` (ou `str_free_tokens()` para matrizes).

### 1. Módulo de Transformação de Case (`str_case.h`)
 - `str_upper(str)`: Retorna cópia da string toda em maiúsculas.
 - `str_lower(str)`: Retorna cópia da string toda em minúsculas.
 - `str_capitalize(str)`: Retorna cópia da string com apenas a primeira letra maiúscula.
 - `str_title(str)`: Retorna cópia da string com a primeira letra de cada palavra maiúscula.

### 2. Módulo de Edição (`str_edit.h`)
 - `str_lstrip(str)`: Remove espaços em branco à esquerda.
 - `str_rstrip(str)`: Remove espaços em branco à direita.
 - `str_strip(str)`: Remove espaços em branco de ambas as extremidades.
 - `str_slice(str, start, end)`: Retorna uma fatia da string baseada em índices (suporta índices negativos).
 - `str_replace(str, old, new)`: Substitui todas as ocorrências de uma substring por outra.

### 3. Módulo de Contagem/Quantificação (`str_count.h`)
 - `str_wordcount(str)`: Conta o número de palavras.
 - `str_linecount(str)`: Conta o número de linhas não vazias.
 - `str_count(str, wrd)`: Conta quantas vezes uma substring específica aparece no texto.

### 4. Módulo de Tokenização (`str_token.h`)
 - `str_splitwords(str)`: Divide a string em um vetor de palavras.
 - `str_splitlines(str)`: Divide a string em um vetor de linhas.
 - `str_free_tokens(tokens, qtd)`: Libera a memória alocada por um vetor de tokens.

## Compilação e Makefile

O projeto utiliza um Makefile para automação. Os seguintes alvos estão disponíveis:

- `make all`: (ou apenas `make`) Compila a biblioteca estática, a dinâmica e a aplicação cliente.
- `make clean`: Remove todos os artefatos de compilação gerados (arquivos `.o`, `.a`, `.so` e binários).
- `make run`: Compila (se necessário) e executa a aplicação cliente.
- `make run_estatico`: Execução com biblioteca estatica
- `make run_dinamico`: Execução com biblioteca dinamica
- `make test`: Compila e executa os testes automatizados da biblioteca.
- `make install`: Instala a biblioteca e os cabeçalhos no sistema.

## Execução
Para executar a aplicação cliente padrão após a compilação, utilize:
`make run`

## Testes
Para rodar os testes automáticos das funções:
`make test`

## Instalação
Para instalar a biblioteca, execute o comando abaixo.
`make install PREFIX=$HOME/.local`