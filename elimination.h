#ifndef ELIMINATION_H
#define ELIMINATION_H

#include <float.h> /* DBL_EPSILON */
#include <math.h>  /* fabs */
#include "linear.h"

/* gaussian_{elimination, var, alt}
    Recebe um sistema linear de ordem n na forma Ax = b
        Calcula o valor do vetor x no intuito de resolver o sistema
    
    Obs: Altera os valores de A e b
*/

void gaussian_elimination(Matrix A, Vector b, Vector x, int order);

void gaussian_var(Matrix A, Vector b, Vector x, int order);

void gaussian_alt(Matrix A, Vector b, Vector x, int order);

/* Recebe um sistema linear Ax = b
    onde A eh uma matriz triangular superior
        calcula o valor de x por retro-substituicao
*/

void back_substitution(Matrix A, Vector x, Vector b, int order);

#endif

