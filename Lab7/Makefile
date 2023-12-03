all:
	g++ -c ATD.cpp
	g++ -c main.cpp
	g++ main.o ATD.o -Wall -o main

gdb:
	g++ -O0 -g3 -c ATD.cpp
	g++ -O0 -g3 -c main.cpp
	g++ main.o ATD.o -Wall -o main