#ifndef LINEAR_H
#define LINEAR_H

#include <stdlib.h> /* malloc, free, atof */
#include <stdio.h>  /* printf */
#include <string.h> /* strtok */

#define B_SIZE 1024

/* Vector */

typedef double* Vector; /* v[k], k \in [0..order-1] */

Vector Vector_create(int order);

Vector Vector_clone(Vector x, int order);

void Vector_destroy(Vector x);

void Vector_print(Vector x, int order);

void Vector_sub(Vector x, Vector y, Vector z,  int order); /* z = x-y */

/* Matrix */

typedef double** Matrix; /* v[l][k], l \in [0..i-1], k \in [0..j-1] */

Matrix Matrix_create(int i, int j);

Matrix Matrix_clone(Matrix A, int i, int j);

void Matrix_destroy(Matrix A, int i);

void Matrix_print(Matrix A, int i, int j);

void Matrix_Vector_mul(Matrix A, Vector x, Vector b, int order); /* b = Ax */

    /* Augmented */

typedef Matrix Augmented;

void Augmented_read(Matrix A, Vector b, int order);

#endif

