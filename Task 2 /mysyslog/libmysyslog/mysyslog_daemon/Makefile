CC=gcc
CFLAGS=-I../libmysyslog/include -L../libmysyslog -lmysyslog
OBJ=daemon.o
TARGET=mysyslog-daemon

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

clean:
    rm -f $(OBJ) $(TARGET)

deb:
    dh_make --createorig -s -p mysyslog-daemon_1.0-1
    dpkg-buildpackage -us -uc
