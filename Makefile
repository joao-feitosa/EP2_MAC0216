CFLAGS = -Wall -Wextra -Iinclude -fPIC
C_FILES = $(wildcard src/*.c)
OBJETOS = $(C_FILES:src/%.c=build/%.o)
LIB_A = lib/libstr_plus.a
LIB_SO = lib/libstr_plus.so
EXEC_ESTATICO = bin/app_estatico
EXEC_DINAMICO = bin/app_dinamico
PREFIX ?= /usr/local

all: $(LIB_A) $(LIB_SO) $(EXEC_ESTATICO) $(EXEC_DINAMICO)

$(LIB_A): $(OBJETOS) | lib
	ar rcs $@ $^

$(LIB_SO): $(OBJETOS) | lib
	gcc -shared -o $@ $^

$(EXEC_ESTATICO): app/main.c $(LIB_A) | bin
	gcc -Wall -Wextra -Iinclude app/main.c $(LIB_A) -o $@

$(EXEC_DINAMICO): app/main.c $(LIB_SO) | bin
	gcc -Wall -Wextra -Iinclude app/main.c -Llib -lstr_plus -Wl,-rpath,lib -o $@

build/%.o: src/%.c | build
	gcc $(CFLAGS) -c $< -o $@

run: run_dinamico

run_estatico: $(EXEC_ESTATICO)
	./$(EXEC_ESTATICO)

run_dinamico: $(EXEC_DINAMICO)
	./$(EXEC_DINAMICO)

test: $(LIB_A) | bin
	gcc -Wall -Wextra -Iinclude tests/main_test.c $(LIB_A) -o bin/app_test
	./bin/app_test

install: all
	mkdir -p $(PREFIX)/include $(PREFIX)/lib
	cp include/*.h $(PREFIX)/include/
	cp $(LIB_A) $(LIB_SO) $(PREFIX)/lib/

build lib bin:
	mkdir -p $@

clean:
	rm -rf build lib bin