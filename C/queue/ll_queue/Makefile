./CC=gcc
DEPS= queue.h
CFLAGS = -I.

%.o %.c: $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

queue: queue.o
		 gcc -o  queue queue.o $(CFLAGS)

clean:
   rm *.o testlfunction
