sort: sort.o readline.o
	gcc -o sort sort.o readline.o

sort.o: sort.c readline.h
	gcc -c sort.c

readline.o: readline.c readline.h
	gcc -c readline.c
