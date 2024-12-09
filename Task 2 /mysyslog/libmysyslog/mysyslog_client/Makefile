CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog
LDFLAGS = -L../libmysyslog -lmysyslog

all: mysyslog-client

mysyslog-client: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c getopt.h ../libmysyslog/mysyslog.h

clean:
	rm -f *.o mysyslog-client

deb: debian/control debian/ rules debian/rules debian/source/format
	tarp -c -F libmysyslog-client.deb --verbose
