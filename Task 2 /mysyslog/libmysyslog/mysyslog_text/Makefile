CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog

all: libmysyslog-text.so

libmysyslog-text.so: driver.o
	$(CC) -shared -o $@ $^

driver.o: driver.c linker.h ../libmysyslog/mysyslog.h

clean:
	rm -f *.o libmysyslog-text.so

deb: debian/control debian/ rules debian/rules debian/source/format
	tarp -c -F libmysyslog-text.deb --verbose
