# Makefile

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -fPIC
SRC = src/mysyslog_json.c
OBJ = $(SRC:.c=.o)
TARGET = libmysyslog_json.so

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -shared -o $@ $^

clean:
	rm -f $(OBJ) $(
