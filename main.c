#include "elimination.h"

int main() {
    char BUFFER[B_SIZE];

    Vector b, x, r;
    Matrix A, C;

    int order, i;

    while (fgets(BUFFER, B_SIZE, stdin)) {
        sscanf(BUFFER, "%d\n", &order);

        A = Matrix_create(order, order);
        x = Vector_create(order);
        b = Vector_create(order);
        r = Vector_create(order);

        Augmented_read(A, b, order);

        for (i = 0; i < 3; ++i) {
            C = Matrix_clone(A, order, order);
            gaussian_elimination(C, b, order); //funct pointer
            //gaussian_var(A, b, order);
            back_substitution(C, x, b, order);
            //unpivot

            puts("Vector x:"); 
                Vector_print(x, order);

            Matrix_Vector_mul(A, x, r, order);
            Vector_sub(r, b, r, order);

            puts("Residuo r:"); 
                Vector_print(r, order);
        }

        Matrix_destroy(A, order);
        Matrix_destroy(C, order);
        Vector_destroy(b);
        Vector_destroy(x);
        Vector_destroy(r);

        fgets(BUFFER, B_SIZE, stdin); /* Ler o readme */ //getchar(); // '\n' || EOF  while (getchar() != '\n') 
    }

    return 0;
}

