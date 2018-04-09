SRC = ray.cpp vector.cpp sphere.cpp light.cpp

OBJ = ray.o vector.o sphere.o light.o

PROG = project4

$(PROG) : $(OBJ)
	g++ $(SRC) -o $(PROG)

$(OBJ) : $(SRC)

clean:
	rm *.o

cleaner:
	rm *~
