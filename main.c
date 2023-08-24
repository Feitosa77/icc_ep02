#include "linear.h"

/**
 * Falta implementar o pivoteamento em todas as EG
 **/

/* 1. Forma classica com pivoteamento */

void gaussian_elimination(Matrix A, Vector b, int order) {
    int i, j, k;
    double m;

    for (i = 0; i < order; ++i)           /* Colunas */
        for (k = i+1; k < order; ++k) {   /* Linhas */
            m = A[k][i] / A[i][i];
            A[k][i] = 0.0;                /* Evitar Erros Numericos -> j = i+1 */

            for (j = i+1; j < order; ++j) /* Deslocamento A[k][j] */
                A[k][j] -= A[i][j] * m;

            b[k] -= b[i] * m;
        }
}

/* 2. Forma classica com pivoteamento, sem o calculo dos multiplicadores */

void gaussian_var(Matrix A, Vector b, int order) {
    int i, j, k;

    for (i = 0; i < order; ++i)           /* Colunas */
        for (k = i+1; k < order; ++k) {   /* Linhas */
            A[k][i] = 0.0;                /* Evitar Erros Numericos -> j = i+1 */

            for (j = i+1; j < order; ++j) /* Deslocamento A[k][j] */
                A[k][j] = A[k][j] * A[i][i] - A[i][j]* A[k][i];

            b[k] = b[k] * A[i][i] - b[i] * A[k][i];
        }
}

/* A is upper triangular */

void back_substitution(Matrix A, Vector x, Vector b, int order) {
    int i, j;

    for (i = order-1; i >= 0; --i) {
        x[i] = b[i];

        for (j = i+1; j < order; ++j)
            x[i] -= A[i][j] * x[j];

        x[i] /= A[i][i];
    }
}

#define B_SIZE 1024

int main() {
    char BUFFER[B_SIZE];

    Vector b, b1,x;
    Matrix A, A1;

    int order;

    while(fgets(BUFFER, B_SIZE, stdin)) {
        sscanf(BUFFER, "%d\n", &order);

        A = Matrix_create(order, order);
        b = Vector_create(order);
        x = Vector_create(order);

        Augmented_read(A, b, order);

        /*
        puts("Matrix A:");
        Matrix_print(A, order, order);

        puts("Vector b:");
        Vector_print(b, order);
        */

        gaussian_elimination(A, b, order);
      //gaussian_var(A, b, order);

        /*
        puts("Matrix A:");
        Matrix_print(A, order, order);

        puts("Vector b:");
        Vector_print(b, order);
        */

        back_substitution(A, x, b, order);

        puts("Vector x:");
        Vector_print(x, order);

        Matrix_destroy(A, order);
        Vector_destroy(b);
        Vector_destroy(x);
    }

    return 0;
}

