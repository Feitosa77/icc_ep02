#include "elimination.h"

/**
 * Falta implementar o pivoteamento em todas as EG
 **/

/* Pivoteamento */

//void pivot(Matrix A, Vector b, int i);
    

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

/* 3. Forma Alternativa (Explicacao no enunciado do ep) */

void gaussian_alt(Matrix A, Vector b, int order) {
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
