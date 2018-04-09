#include <stdio.h>
#include <stdlib.h>

typedef double vec_t[3];

typedef struct {
   vec_t row[3];
}matrix_t;

int matrix_load(matrix_t*);
void matrix_print(char*, matrix_t*);
void matrix_copy(matrix_t* dest, matrix_t* src);
void matrix_sum(matrix_t* result, matrix_t m1, matrix_t m2);
void matrix_diff(matrix_t* result, matrix_t m1, matrix_t m2);
void matrix_scale(matrix_t* result, matrix_t m1, double scale);
void matrix_mult(matrix_t* result, matrix_t m1, matrix_t m2);


