all:
	cd 1a && ./run.sh;
	cd 1b && ./run.sh;
	cd 2 && ./run.sh;
	cd 3 && ./run.sh;
	cd 5 && $(MAKE)
	cd 6 && $(MAKE)

clean:
	find . -name "*.o" -delete
	find . -name "*.so" -delete
	find . -name "*.a" -delete
	find . -name "*.out" -delete

.PHONY: all clean
