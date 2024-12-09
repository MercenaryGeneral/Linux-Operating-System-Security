CC=gcc
CFLAGS=-I../libmysyslog/include -L../libmysyslog -lmysyslog
OBJ=client.o
TARGET=mysyslog-client

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CC) -o $@ $^ $(CFLAGS)

clean:
    rm -f $(OBJ) $(TARGET)

deb:
    dh_make --createorig -s -p mysyslog-client_1.0-1
    dpkg-buildpackage -us -uc
