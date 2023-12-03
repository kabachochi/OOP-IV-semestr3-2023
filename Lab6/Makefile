all:
	g++ -c Rectangles.cpp
	g++ -c main.cpp
	g++ Rectangles.o main.o -o Rectangles -lsfml-graphics -lsfml-window -lsfml-system

gdb:
	g++ -O0 -g3 -c Rectangles.cpp
	g++ -O0 -g3 -c main.cpp
	g++ Rectangles.o main.o -o Rectangles -lsfml-graphics -lsfml-window -lsfml-system