# Relevant directories
IDIR=../inc
ODIR=../obj

# The compiler and compilation flags
CC=gcc
CFLAGS=-Wall
LIBS=-lm

# Dependencies and object files
DEPS=util.h stats.h queue.h
OBJ=proj2.o stats.o queue.o

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

proj2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
