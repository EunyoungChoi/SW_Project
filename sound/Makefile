OUTPUT = libfuncs.a
OBJECT = playmusic.o
.PHONY:clean

$(OUTPUT): $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)


$(OBJECT): playmusic.c
	gcc -c playmusic.c -o playmusic.o

clean:
	rm -f $(OBJECT) $(OUTPUT)
