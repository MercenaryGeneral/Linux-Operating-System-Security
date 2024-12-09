CC = gcc
CFLAGS = -Wall -Werror -I../libmysyslog
LDFLAGS = -L../libmysyslog -lmysyslog

.PHONY: all clean deb install systemctl-enable systemctl-disable

all: mysyslog-daemon mysyslog-daemon.service

mysyslog-daemon: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c syslog.h sys/stat.h sys/types.h unistd.h signal.h getopt.h sys/systemd/sd-daemon.h sys/systemd/sd-journal.h $(include_dirs) ../libmysyslog/mysyslog.h

mysyslog-daemon.service: service.tpl
	envsubst < service.tpl > mysyslog-daemon.service

clean:
	rm -f *.o mysyslog-daemon mysyslog-daemon.service

deb: debian/control debian/ rules debian/rules debian/source/format
	dpkg-buildpackage -rfakeroot -uc -b

install: deb
	dpkg -i ../$(basename mysyslog-daemon.deb)
	systemctl daemon-reload

systemctl-enable: deb
	systemctl enable mysyslog-daemon

systemctl-disable: deb
	systemctl disable mysyslog-daemon
