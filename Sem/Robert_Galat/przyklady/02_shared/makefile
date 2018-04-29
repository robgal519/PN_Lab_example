00.o: 00.c
	gcc -c -fPIC 00.c
01.o: 00.c
	gcc -c 01.c

lib00.so: 00.o 
	gcc -shared -o lib00.so 00.o

a.out: 01.o lib00.so
	gcc -L. 01.o -l00

run: a.out
	export LD_LIBRARY_PATH=.;./a.out

readelf:lib00.so
	readelf -h lib00.so | grep Type

clean:
	rm *.so *.o* 
