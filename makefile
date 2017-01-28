CC = i386-aros-gcc
CFLAGS =
LDFLAGS =

PROG = ZTans

OBJ = src/main.o src/interface.o src/compatibility.o
# src/support.o src/callbacks.o

$(PROG): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROG)

all: $(PROG)

src/callbacks.o: src/callbacks.c src/callbacks.h src/compatibility.h
src/interface.o: src/interface.c src/interface.h src/compatibility.h
src/main.o: src/main.c src/main.h src/compatibility.h
src/support.o: src/support.c src/support.h src/compatibility.h
src/compatibility.o: src/compatibility.c src/compatibility.h

clean: 
	rm -f *.o $(PROG)
