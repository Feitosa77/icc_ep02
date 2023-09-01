#include "linear.h"

/* Vector */

Vector Vector_create(int order) {
    return malloc(sizeof (double) * order);
}

void Vector_destroy(Vector x) {
    free(x);
}

void Vector_print(Vector x, int i) {
    for (int k = 0; k < i; ++k)
        printf(" %lf ", x[k]);
    printf("\n\n");
}

void Vector_sub(Vector x, Vector y, Vector z, int order) {
    for (int i = 0; i < order; ++i)
        z[i] = x[i] - y[i];
}

/* Matrix */

Matrix Matrix_create(int i, int j) {
    Matrix A = malloc(sizeof (double*) * i);

    for (i = 0; i < j; ++i)
        A[i] = malloc(sizeof (double) * j);

    return A;
}

Matrix Matrix_clone(Matrix A, int i, int j) {
    Matrix C = Matrix_create(i, j); 

    for (int k = 0; k < i; ++k)
        for (int l = 0; l < j; ++l)
            C[k][l] = A[k][l];

    return C;
}

void Matrix_destroy(Matrix A, int i) {
    while (i)
        free(A[--i]);

    free(A);
}

void Matrix_print(Matrix A, int i, int j) {
    for (int l = 0; l < i; ++l) {
        for(int k = 0; k < j; ++k)
            printf(" %lf ", A[l][k]);
        putchar('\n');
    }
    
    putchar('\n');
}

void Matrix_Vector_mul(Matrix A, Vector x, Vector b, int order) {
    int i, j;

    for (i = 0; i < order; ++i)
        b[i] = 0;

    for (i = 0; i < order; ++i)
        for (j = 0; j < order; ++j) 
            b[i] += A[i][j] * x[i];
}

    /* Augmented */

void Augmented_read(Matrix A, Vector b, int order) {
    char BUFFER[B_SIZE], *token;

    for (int i = 0; i < order; ++i) {
        fgets(BUFFER, B_SIZE, stdin);
        token = strtok(BUFFER, " ");

        for (int j = 0; j < order; ++j) {
            A[i][j] = atof(token);
            token = strtok(NULL, " ");
        }
        b[i] = atof(token);
    }
}

