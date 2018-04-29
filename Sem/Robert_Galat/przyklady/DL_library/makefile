foo.o:foo.c
	gcc -c -fPIC foo.c

libfoo.so:foo.o
	gcc -shared -o libfoo.so foo.o

example.o: example.c
	gcc -c example.c

a.out: example.o
	gcc example.o -ldl