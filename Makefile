CC=gcc
CFLAGS=-O0 -g -Wall -Wextra
program=timeout

.PHONY: all clean
all: $(program)

$(program): main.o options.o

timeout.o: timeout.h
main.o: options.h timeout.h
options.o: timeout.h

clean:
	rm -f *.o $(program)


