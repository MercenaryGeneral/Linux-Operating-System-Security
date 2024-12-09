CC=gcc
CFLAGS=-Iinclude -fPIC
OBJ=mysyslog.o
TARGET=libmysyslog.so

all: $(TARGET)

$(TARGET): $(OBJ)
    gcc -shared -o $@ $^

clean:
    rm -f $(OBJ) $(TARGET)

deb:
    dh_make --createorig -s -p libmysyslog_1.0-1
    dpkg-buildpackage -us -uc
