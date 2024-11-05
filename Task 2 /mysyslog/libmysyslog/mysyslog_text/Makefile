# Makefile

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -fPIC
SRC = src/mysyslog_text.c
OBJ = $(SRC:.c=.o)
TARGET = libmysyslog_text.so

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -shared -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
