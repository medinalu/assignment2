CC=gcc --std=c99 -g

all: test_pq 

test_pq: test_pq.c pq.o dynarray.o
	$(CC) test_pq.c pq.o dynarray.o -o test_pq

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

pq.o: pq.c pq.h
	$(CC) -c pq.c

clean:
	rm -f *.o test_pq 

