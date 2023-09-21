all:
	mkdir bin
	gcc main.c include/*.h include/*.c -o bin/clipg