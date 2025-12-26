CC = gcc
CFLAGS = -Wall -Wextra

test: main.c my_list_shallow.c
	$(CC) $(CFLAGS) -o test main.c my_list_shallow.c
	./test

clean:
	rm -f test