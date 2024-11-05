# Makefile

CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC = src/mysyslog.c
OBJ = $(SRC:.c=.o)
TARGET = libmysyslog.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
