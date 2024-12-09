CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog
LDFLAGS = -L../libmysyslog -lmysyslog

all: mysyslog-client

mysyslog-client: main.o
	$(CC) -o $@ $^ $(LDFLAGS) $(include_dirs)

main.o: main.c getopt.h $(include_dirs) ../libmysyslog/mysyslog.h

clean:
	rm -f *.o mysyslog-client
