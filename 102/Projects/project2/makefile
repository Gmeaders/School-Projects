SRC = ray.c vector.c light.c plane.c sphere.c

OBJ = ray.o vector.o light.o plane.o sphere.o

PROG = project2

$(PROG) : $(OBJ)
	gcc $(SRC) -o $(PROG) -lm

$(OBJ) : $(SRC)

clean:
	rm *.o

cleaner:
	rm *~
