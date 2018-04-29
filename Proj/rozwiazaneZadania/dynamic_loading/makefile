all: main.out
	./main.out

main.out: main.c libfoo.so
	gcc main.c -o main.out -ldl

libfoo.so: foo.c
	gcc -shared foo.c -o libfoo.so -fpic

clean:
	rm -f *.out *.so

.PHONY: all clean
