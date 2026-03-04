CC=gcc
CFLAGS=-g -Wall
OBJS=memoria_compartida.o
EXE=escribeMemCompartida.elf leeMemCompartida.elf destruyeMemCompartida.elf

all: $(EXE)

%.elf: %.o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o $@

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.dSYM *.o $(EXE)