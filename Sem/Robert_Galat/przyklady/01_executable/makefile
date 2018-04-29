
*.o: *.c
	gcc -c $^

clean:
	rm *.o*

compile: *.c
	clear && gcc 01.c 

link: *.o
	cd 00; make; cd ..; gcc 01.o 00/00.o

symbols: *.o link
	clear; readelf --symbols *.o; echo "===============================================================================================================";readelf --symbols *.out
