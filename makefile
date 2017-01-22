CC = i386-aros-gcc
CFLAGS =
LDFLAGS =

PROG = ZTans

OBJ = src/main.o src/interface.o
# src/support.o src/callbacks.o

$(PROG): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROG)

all: $(PROG)

src/callbacks.o: src/callbacks.c src/callbacks.h 
src/interface.o: src/interface.c src/interface.h
src/main.o: src/main.c src/main.h
src/support.o: src/support.c src/support.h

clean: 
	rm -f *.o $(PROG)
