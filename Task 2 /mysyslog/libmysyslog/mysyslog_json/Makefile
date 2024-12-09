CC=gcc
CFLAGS=-Iinclude -fPIC
OBJ=json_driver.o
TARGET=libmysyslog-json.so

all: $(TARGET)

$(TARGET): $(OBJ)
    gcc -shared -o $@ $^

clean:
    rm -f $(OBJ) $(TARGET)

deb:
    dh_make --createorig -s -p libmysyslog-json_1.0-1
    dpkg-buildpackage -us -uc
