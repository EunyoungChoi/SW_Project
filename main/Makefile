.PHONY: clean

main: main.c
	gcc `pkg-config --cflags --libs gtk+-2.0` -o main main.c -Wall -L../sound -lfuncs -I../include/ -L../action -lbonus -I../include/-O2 -lpthread
main.o: main.c
	gcc -c main.c main.o
clean: rm main main.o
