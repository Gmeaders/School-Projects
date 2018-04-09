CC=gcc
CFLAGS=-I.
LIBS=-lncurses -lpthread
DEPS=chatui.h chatnet.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

chatlab: chatui.o chatnet.o 
	gcc -o chatlab main.c chatui.o chatnet.o $(CFLAGS) $(LIBS)
	
clean:
	rm -f *.o chatlab