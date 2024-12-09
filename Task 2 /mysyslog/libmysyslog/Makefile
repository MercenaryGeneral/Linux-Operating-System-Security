CC = gcc
CFLAGS = -Wall -Werror

all: libmysyslog.a

libmysyslog.a: mysyslog.o
	$(CC) -shared -o $@ $^

mysyslog.o: mysyslog.c mysyslog.h

clean:
	rm -f *.o libmysyslog.a

deb: debian/control debian/ rules debian/rules debian/source/format
	tarp -c -F libmysyslog.deb --verbose
