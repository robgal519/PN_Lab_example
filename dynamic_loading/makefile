
a.out: main.c libfoo.so
	gcc main.c -ldl

libfoo.so: foo.c
	gcc -shared foo.c -o libfoo.so -fpic