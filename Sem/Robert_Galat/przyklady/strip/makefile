SHELL:=/bin/bash -O extglob

all: strip

*.o: *.c
	gcc -c $^

clean:
	rm *.o*; cd 00; make clean;

a.out: *.o
	cd 00; make; cd ..; gcc 01.o 00/00.o

strip: a.out
	strip a.out -o stripped.out

nm: a.out
	nm a.out

diff: a.out strip
	diff  <(objdump -d a.out|grep '#') <(objdump -d stripped.out | grep '#')

