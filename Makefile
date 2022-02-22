CC=gcc

CFLAGS =`pkg-config --cflags --libs gtk+-3.0`
CFLAGS+= -rdynamic


automacro: main.o clicker_gui.o
	$(CC) main.o clicker_gui.o -lm $(CFLAGS) -o automacro


main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

clicker_gui.o: src/clicker_gui.c
	$(CC) $(CFLAGS) -c src/clicker_gui.c


clean:
	rm *.o automacro || true
