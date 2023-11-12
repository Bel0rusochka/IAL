CC=gcc
CFLAGS=-Wall -std=c11 -pedantic -lm

main: main.c node.c edge.c reader.c 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f main