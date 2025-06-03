CC = gcc # comipler
CFLAGS = -O3 -march=native -flto # optimized
ASMFLAGS = -f elf64 # building for 64 to use 64bits of space per register so less memory efficient but better runtime!
LDFLAGS = -flto # link time optimization compiler optimizes code(removes unnecessary functions and data) and uses cache, for all source files, saves time while run

all: std_bench asm_bench # the two bin files

std_bench: standard_vector_benchmark.c
	$(CC) $(CFLAGS) $< -o $@

vector_asm.o: vector.asm
	nasm $(ASMFLAGS) $< -o $@

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c $< -o $@

asm_bench: asm_vector_benchmark.c vector.o vector_asm.o
	$(CC) $(CFLAGS) $(LDFLAGS) $< vector.o vector_asm.o -o $@

clean:
	rm -f *.o std_bench asm_bench
