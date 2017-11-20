CFLAGS = -Wall --std=c11 -Wno-missing-braces -Wno-switch -Wno-int-conversion -Wno-unused-function -g
CC=gcc

.PHONY: clean


all: arena


arena: arena.o maq.o pilha.o
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f *.o *~ *.out arena
