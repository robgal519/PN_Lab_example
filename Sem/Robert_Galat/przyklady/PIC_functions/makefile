SHELL:=/bin/bash -O extglob
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

