all: windows linux

linux:
	gcc main.c -Ofast -funroll-loops -o main.elf

windows:
	i686-w64-mingw32-gcc main.c -Ofast -funroll-loops -o main.exe