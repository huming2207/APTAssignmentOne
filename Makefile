CC 	= clang
EXEC 	= CarBoard
CFLAG 	= -pedantic -Wall -o

all:
	$(CC) $(CFLAG) $(EXEC) *.c

debug:
	$(CC) -g $(CFLAG) $(EXEC) *.c

clean:
	rm -rf *.o
	rm -rf $(EXEC)
