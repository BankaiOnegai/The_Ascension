all:  PROJET EXECUTION

main.o: main.c header.h
		gcc -c main.c 

menu.o: menu.c
		gcc -c menu.c 

prog.o: prog.c
		gcc -c prog.c

algo.o: algo.c
		gcc -c algo.c 

PROJET:  main.o menu.o prog.o algo.o 
		gcc -o PROJET main.o menu.o prog.o algo.o  -Wall

EXECUTION:
			./PROJET

