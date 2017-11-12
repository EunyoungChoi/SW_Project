.PHONY: clean

testmain: testmain.o
	gcc -o testmain -L../lib testmain.o -lfuncs

testmain.o: testmain.c
	gcc -g -c -I../include testmain.c -o testmain.o
clean:
	rm -f *.o testmain
