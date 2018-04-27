#!/bin/sh -x
rm -f *.out *.o *.a *.so

# Skompiluj pliki first.c i second.c z odpowiednimi flagami

# Stwórz bibliotekę współdzielone w oparciu o wyniki kompilacji powyższych
# plików

# Skompiluj plik main.c

# Zlinkuj efekt kompilacji pliku main.c z biblioteką współdzieloną

# Uruchom program

# Na potrzeby nastepnego zadania :) (nie zmieniać)
cp -f main.out ../ld_preload/.
