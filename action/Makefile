.PHONY : clean
libfuncs.a : bonus.o
	ar rv libbonus.a bonus.o
bonus.o : bonus.c
	gcc -c -g bonus.c -o bonus.o
clean:
	rm -f *.o
