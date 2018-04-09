SRC = ray.c vector.c light.c plane.c sphere.c box.c

OBJ = ray.o vector.o light.o plane.o sphere.o box.o

PROG = project3

$(PROG) : $(OBJ)
	gcc $(SRC) -o $(PROG) -lm

$(OBJ) : $(SRC)

clean:
	rm *.o

cleaner:
	rm *~
