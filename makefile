INCLUDE = -I ./include
LIBDIR = ./libfdr
CC = gcc
LIBS = $(LIBDIR)/libfdr.a
CFLAGS = -g $(INCLUDE)
ALL = compile
RUN = clean compile

all: $(ALL)

clean:
	rm -f *.o kripto

cleanall: 
	rm -f decripted encripted .kilit ornek_metin *.o kripto *.txt core $(ALL)

compile:
	$(CC) $(INCLUDE) -o kripto ./src/main.c $(LIBS)

run: $(RUN)
	./kripto -e istiklal_marsi_2.txt encripted
	./kripto -d encripted decripted
	


