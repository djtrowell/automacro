CC=gcc

CFLAGS =`pkg-config --cflags --libs gtk+-3.0`
CFLAGS+= -rdynamic


automacro: main.o main_gui.o macro_gui.o clicker_gui.o
	$(CC) main.o main_gui.o macro_gui.o clicker_gui.o -lm $(CFLAGS) -o automacro


main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

main_gui.o: src/main_gui.c
	$(CC) $(CFLAGS) -c src/main_gui.c

macro_gui.o: src/macro_gui.c
	$(CC) $(CFLAGS) -c src/macro_gui.c

clicker_gui.o: src/clicker_gui.c
	$(CC) $(CFLAGS) -c src/clicker_gui.c


clean:
	rm *.o automacro || true
