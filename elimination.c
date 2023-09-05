#include "elimination.h"

/**
 * Falta implementar o pivoteamento em todas as EG
 **/

/* Pivoteamento */

void pivot(Matrix A, Vector b, int i, int *buf) {
 
}

void unpivot(Vector x, int *buf) {

}
    

/* 1. Forma classica com pivoteamento */

void gaussian_elimination(Matrix A, Vector x, Vector b, int order) {
    int i, j, k;
    double m;

    for (i = 0; i < order; ++i)           /* Colunas */
        for (k = i+1; k < order; ++k) {   /* Linhas */
            m = A[k][i] / A[i][i];

            for (j = i; j < order; ++j) /* Deslocamento A[k][j] */
                A[k][j] -= A[i][j] * m;

            b[k] -= b[i] * m;
        }

      back_substitution(A, x, b, order);
      //unpivot(x);
}

/* 2. Forma classica com pivoteamento, sem o calculo dos multiplicadores */

void gaussian_var(Matrix A, Vector x, Vector b, int order) {
    int i, j, k;
    double m;

    for (i = 0; i < order; ++i)         /* Colunas */
        for (k = i+1; k < order; ++k) { /* Linhas */
            m = A[k][i];

            for (j = i; j < order; ++j) /* Deslocamento A[k][j] */
                A[k][j] = A[k][j] * A[i][i] - A[i][j] * m;

            b[k] = b[k] * A[i][i] - b[i] * m;
        }
        
      back_substitution(A, x, b, order);
      //unpvot(x);
}

/* 3. Forma Alternativa (Explicacao no enunciado do ep) */

void gaussian_alt(Matrix A, Vector x, Vector b, int order) {
    int i, j, k;
    double m;

    for (i = 0; i < order; ++i) {  
        for (j = i, m = A[i][i]; j < order; ++j) /* Dividir os coeficientes pelo pivo */ 
            A[i][j] /= m;
        b[i] /= m;

        for (k = i+1; k < order; ++k) {          /* Proceder com a eliminacaos */
            m = A[k][i];

            for (j = i; j < order; ++j)          
                A[k][j] -= A[i][j] * m;

            b[k] -= b[i] * m;
        }
    }

    back_substitution(A, x, b, order); /* Calcular por retro-substituicao */
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
