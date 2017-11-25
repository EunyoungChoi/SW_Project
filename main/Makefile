.PHONY: clean

main: main.c
	gcc 'pkg-config --cflag gtk+-2.0' -o main main.c 'pkg-config --libs gtk+-2.0' -L../sound -lfuncs -I../include/ -L../action -lbonus -I../include/-O2 -lpthread

clean: rm main main.o
