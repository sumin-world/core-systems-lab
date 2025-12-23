CC = gcc
CFLAGS = -Wall -Wextra -std=c11

test: test_memory.c my_memory.c
	$(CC) $(CFLAGS) -o test test_memory.c my_memory.c
	./test

clean:
	rm -f test