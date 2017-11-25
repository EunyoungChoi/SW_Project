OUTPUT = libfuncs.a
OBJECT = playmusic.o
GCC = gcc -c
.PHONY:clean

$(OUTPUT): $(OBJECT)
	ar rv $(OUTPUT) $(OBJECT)


$(OBJECT): playmusic.c
	$(GCC) playmusic.c -o $(OBJECT)

clean:
	rm -f $(OBJECT) $(OUTPUT)
