#ifndef LINEAR_H
#define LINEAR_H

#include <stdlib.h> /* malloc, free, atof */
#include <stdio.h>  /* printf */
#include <string.h> /* strtok */

#define B_SIZE 1024

/* Vector */

typedef double* Vector; /* v[k], k \in [0..order-1] */

Vector Vector_create(int order);

void Vector_destroy(Vector x);

void Vector_print(Vector x, int order);

//void Vector_sum(Vector x, Vector y, int order);

//void Vector_mul(Vector x, Vector y, int order);

/* Matrix */

typedef double** Matrix; /* v[l][k], l \in [0..i-1], k \in [0..j-1] */

Matrix Matrix_create(int i, int j);

void Matrix_destroy(Matrix A, int i);

void Matrix_print(Matrix A, int i, int j);

    /* Augmented */

typedef Matrix Augmented;

void Augmented_read(Matrix A, Vector b, int order);

#endif

