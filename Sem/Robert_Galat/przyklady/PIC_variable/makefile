SHELL:=/bin/bash -O extglob

all: a.out

foo.o: foo.c
	gcc -c -fPIC -g foo.c
a.out:example.c libfoo.so
	gcc -g example.c -L. -lfoo

libfoo.so: foo.o 
	gcc -shared -o libfoo.so foo.o

run:a.out
	export LD_LIBRARY_PATH=.; ./a.out
objdump:libfoo.so
	./dump.sh

clean:
	rm foo.o a.out libfoo.so
