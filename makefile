
INCLUDE = -I ./include
LIBDIR = ./libfdr
CC = gcc
LIBS = $(LIBDIR)/libfdr.a
CFLAGS = -g $(INCLUDE)
ALL = odev

all: $(ALL)

clean:
	rm -f *.o core $(ALL)

odev:
	$(CC) $(INCLUDE) -o program.o ./src/main.c $(LIBS)


