CC=gcc
CFLAGS=-Iinclude -fPIC
OBJ=text_driver.o
TARGET=libmysyslog-text.so

all: $(TARGET)

$(TARGET): $(OBJ)
    gcc -shared -o $@ $^

clean:
    rm -f $(OBJ) $(TARGET)

deb:
    dh_make --createorig -s -p libmysyslog-text_1.0-1
    dpkg-buildpackage -us -uc
