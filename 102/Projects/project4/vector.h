/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	vector.h
*/
#ifndef VECTOR_H
#define VECTOR_H

class VECTOR {
  double x, y, z;

public:
  VECTOR () {};

  VECTOR (double x, double y, double z)
  {
    this -> x = x;
    this -> y = y;
    this -> z = z;
  }

  VECTOR set (double x, double y, double z)
  {
    this -> x = x;
    this -> y = y;
    this -> z = z;

    return *this;
  }

  VECTOR normalize ();

  VECTOR add (VECTOR v2);
  VECTOR operator+ (VECTOR v2);

  VECTOR subtract (VECTOR v2);
  VECTOR operator- (VECTOR v2);

  VECTOR multiply (VECTOR v2);
  VECTOR operator* (VECTOR v2);

  VECTOR scalar_mult (double s);
  VECTOR operator* (double s);

  VECTOR scalar_divide (double s);
  VECTOR operator/ (double s);

  double dot (VECTOR v2);

  double length (void);

  double calculate_b(VECTOR v2);

  double calculate_c(VECTOR v2, double r);

  VECTOR calculate_r(VECTOR normal, double temp);

};

#endif


