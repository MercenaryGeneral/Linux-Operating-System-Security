CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog

.PHONY: all clean deb

all: libmysyslog-text.so

libmysyslog-text.so: driver.o
	$(CC) -shared -o $@ $^

driver.o: driver.c linker.h ../libmysyslog/mysyslog.h

clean:
	rm -f *.o libmysyslog-text.so
