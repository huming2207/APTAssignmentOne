CC 	= gcc
CLANG_C = clang
EXEC 	= CarBoard
CFLAG 	= -ansi -pedantic -Wall -o

all:
	$(CC) $(CFLAG) $(EXEC) *.c

debug:
	$(CC) -g $(CFLAG) $(EXEC) *.c

clang:
	$(CLANG_C) $(CFLAG) $(EXEC) *.c

clang-debug:
	$(CLANG_C) -g $(CFLAG) $(EXEC) *.c

clean:
	rm -rf $(EXEC)
