CFLAGS=-c -g 
LDFLAGS=


test1: test1.o graphe.o liste.o
	gcc -o $@ $^  $(LDFLAGS)


%.o: %.c
	gcc $(CFLAGS) $< 

clean:
	rm *.o 



