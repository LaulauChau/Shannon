
OBJ=core.o io.o
CC=gcc

core:	$(OBJ) core.h types.h
	$(CC) $(OBJ) -o core

%.o :	%.c
	$(CC)  -c $<

clean:
	@rm -f *.o
	@rm -f core
	@rm -f *~

