IDIR=inc
CC=gcc
CFLAGS=-Wall

ODIR=obj
LIBS=-lm

DEPS = queue.h stats.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CLFAGS)

proj2: $(OBJ)
	$(CC) proj2.c -o proj2 $(LIBS) $(CFLAGS)
