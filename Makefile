CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

all:

	@mkdir -p bin
	$(CC) $(CFLAGS) app/main.c src/*.c -o bin/app

run:
	./bin/app

clean:
	rm -rf bin/*