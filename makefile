
INCLUDE = -I ./include
LIBDIR = ./libfdr
CC = gcc
LIBS = $(LIBDIR)/libfdr.a
CFLAGS = -g $(INCLUDE)
ALL = odev
RUN = make

all: $(ALL)

clean:
	rm -f *.o kripto core $(ALL)

cleanall: 
	rm -f decrypted encrypted .kilit ornek_metin kripto *.txt core $(ALL)

odev:
	$(CC) $(INCLUDE) -o kripto ./src/main.c $(LIBS)

run:
	$(RUN)
	./kripto -e input.txt encripted
	./kripto -d encripted decripted
	




