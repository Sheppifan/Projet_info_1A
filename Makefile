CFLAGS=-c -g -Wall -Wextra
LDFLAGS=

test1: test1.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)
test2: test2.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)
test3: test3.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)
test4: test4.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)

main: main.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<

all: test1 test2 test3 test4 main

clean:
	rm -f *.o test? *~
	rm -f *.o main *~


