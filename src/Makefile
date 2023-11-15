CC=gcc
CFLAGS=-Wall -std=c11 -pedantic -lm
FILES=main.c node.c edge.c reader.c algorithm.c list.c set.c

main: $(FILES)
	$(CC) $(CFLAGS) -o $@ $(FILES)

clean:
	rm -f main
