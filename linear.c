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

/* Matrix */

Matrix Matrix_create(int i, int j) {
    Matrix A = malloc(sizeof (double*) * i);

    for (i = 0; i < j; ++i)
        A[i] = malloc(sizeof (double) * j);

    return A;
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

