CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog -I/usr/local/include/json-c

.PHONY: all clean deb

all: libmysyslog-json.so

libmysyslog-json.so: driver.o
	$(CC) -shared -o $@ $^

driver.o: driver.c linker.h ../libmysyslog/mysyslog.h json-c/json.h

clean:
	rm -f *.o libmysyslog-json.so
