CC=g++
CFLAGS=-I.
DEPS=price.h item.h inventory.h billofsale.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chatlab: price.o item.o inventory.o billofsale.o
	$(CC) -o lab11 main.cpp price.o item.o inventory.o billofsale.o $(CFLAGS)
	
clean:
	rm -f *.o lab11