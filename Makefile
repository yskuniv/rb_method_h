CC	= gcc
CFLAGS	= -Wall -std=gnu99

sample.out: sample.c
	$(CC) $(CFLAGS) $< -o $@

check-syntax: CFLAGS += -fsyntax-only -x c
check-syntax:
	$(CC) $(CFLAGS) $(CHK_SOURCES)

clean:
	rm -f *.o *.out *~
