CC=gcc
CFLAGS=-c -g -ansi -pedantic -Wall
OBJ=main.o peak.o
EXEC=find_peak
DBG=core vgcore.*

ALL : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	-rm -f $(OBJ)

main.o : main.c main.h peak.h
	$(CC) main.c $(CFLAGS)

peak.o : peak.c peak.h
	$(CC) peak.c $(CFLAGS)

clean :
	-rm -f $(OBJ) $(DBG) $(EXEC)

