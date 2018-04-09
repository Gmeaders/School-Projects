OBJS= lab3.o \
 bit.o

INCS= lab3.h
bittest: ${OBJS}
	@echo
	@echo Compiling bitwise operations library $@   
	gcc -o $@ -Wall -g ${OBJS}

.c.o: $<
	@echo
	@echo Compiling $*.c
	-gcc -c -Wall -c -g $<  2> ${@:.o=.err}
	@cat $*.err

${OBJS}: ${INCS} makefile

clean:
	rm -rf a.out *.o *.err

