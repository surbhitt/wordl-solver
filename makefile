CC=clang++
FLAGS=-g
all: main.cpp 
	$(CC) $(FLAGS) main.cpp -o solver
