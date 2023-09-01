#ifndef ELIMINATION_H
#define ELIMINATION_H

#include "linear.h"

void gaussian_elimination(Matrix A, Vector b, int order);

void gaussian_var(Matrix A, Vector b, int order);

void gaussian_alt(Matrix A, Vector b, int order);

void back_substitution(Matrix A, Vector x, Vector b, int order);

#endif

