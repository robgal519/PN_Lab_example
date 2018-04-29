
00.o: 00.c
	gcc -c 00.c

nm: 00.o
	nm 00.o
show_source:
	clear && pygmentize 00.c

readelf: 00.o
	readelf -h 00.o | grep Type

clean:
	rm *.o
