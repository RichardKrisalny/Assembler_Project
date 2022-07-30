start: firstRead.o secondRead.o macroChange.o asembler.o
	gcc -ansi -Wall -pedantic -g firstRead.o secondRead.o macroChange.o asembler.o -o start -lm
firstRead.o: firstRead.c data.h dataAms.h
	gcc -c -ansi -Wall -pedantic firstRead.c -o firstRead.o -lm
secondRead.o: secondRead.c data.h dataAms.h
	gcc -c -ansi -Wall -pedantic secondRead.c -o secondRead.o -lm
macroChange.o: macroChange.c data.h 
	gcc -c -ansi -Wall -pedantic macroChange.c -o macroChange.o -lm
asembler.o: asembler.c data.h
	gcc -c -ansi -Wall -pedantic asembler.c -o asembler.o -lm
