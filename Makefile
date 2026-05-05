CC=gcc
WINCC=x86_64-w64-mingw32-gcc
CFLAGS=-O2 -Wall -Wextra -pedantic
SRC=src/alap.c

all:
	$(CC) $(CFLAGS) $(SRC) -o alap-linux-x86_64

win:
	$(WINCC) $(CFLAGS) $(SRC) -o alap-windows-x86_64.exe

clean:
	rm -f alap-linux-x86_64 alap-windows-x86_64.exe
