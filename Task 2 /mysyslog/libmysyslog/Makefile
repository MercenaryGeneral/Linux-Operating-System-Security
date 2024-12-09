CC = gcc
CFLAGS = -Wall -Werror

.PHONY: all clean deb install

all: libmysyslog.a

libmysyslog.a: mysyslog.o
	$(CC) -shared -o $@ $^

mysyslog.o: mysyslog.c mysyslog.h

clean:
	rm -f *.o libmysyslog.a
