#modify this makefile so that it will work for this new assignment
CC=g++
V =-std=c++11

all:  main.o
	$(CC) $(V) main.o -o a.out

main: main.o 
	$(CC) -c $(V) main.cpp

clean: 
	rm *.o 
	rm *.out
