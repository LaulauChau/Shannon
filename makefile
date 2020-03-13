
OBJ=Core.o io.o
CC=gcc

Core:	$(OBJ) Core.h types.h
	$(CC) $(OBJ) -o Core

%.o :	%.c
	$(CC)  -c $<

clean:
	@rm -f *.o
	@rm -f core
	@rm -f *~

