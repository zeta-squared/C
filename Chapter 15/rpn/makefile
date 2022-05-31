rpn: rpn.o stack.o
	gcc -o rpn rpn.o stack.o

rpn.o: rpn.c stack.h
	gcc -c rpn.c

stack.o: stack.c stack.h
	gcc -c stack.c
