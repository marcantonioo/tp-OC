all: main.o
	@gcc main.o -o exe -lm
	@rm -r main.o
main.o: main.c
	@gcc main.c -c -Wall
run:
	@./exe
val:
	@gcc -g -o exeval main.c -Wall -lm
valrun: val
	@valgrind --leak-check=full --track-origins=yes -s ./exeval

