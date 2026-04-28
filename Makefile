CC=gcc
CFLAGS=-O2 -Wall -Wextra -pedantic
TARGET=alap
SRC=src/alap.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
