CC=clang
DEPS= array.h
CFLAGS = -I.
EXE  = array
SRCS = array.c
LIBS =
%.o %.c: $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

OBJS = $(SRCS:.c=.o)

$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm -r core $(EXE)*.o
