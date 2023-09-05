#include "elimination.h"
#include <likwid.h>
#include <sys/time.h>

#define N_ELIMINATIONS 3

/* Funcao dos slides da materia */

double timestamp() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return ((double) (tp.tv_sec/1000 + tp.tv_usec));
}

int main() {
    void (*elimination[N_ELIMINATIONS])(Matrix, Vector, Vector, int) = {gaussian_elimination, gaussian_var, gaussian_alt};
    char BUFFER[B_SIZE];

    char MARKER_NAME[] = "MarkerI";

    Vector b, bl, x, r;
    Matrix A, Al;

    int order, i;
    double time;

    LIKWID_MARKER_INIT;

    while (fgets(BUFFER, B_SIZE, stdin)) {
        sscanf(BUFFER, "%d\n", &order);

        A = Matrix_create(order, order);
        x = Vector_create(order);
        b = Vector_create(order);
        r = Vector_create(order);

        Augmented_read(A, b, order);

        for (i = 0; i < N_ELIMINATIONS; ++i) { /* Para cada eliminacao de gauss */

            /* Copia os valores do sistema Ax = b */
            Al = Matrix_clone(A, order, order);
            bl = Vector_clone(b, order);

            MARKER_NAME[6] = i+48; /* MARKER_NAME := "MarkerI" */

            LIKWID_MARKER_START(MARKER_NAME);
                time = timestamp();
                    (*elimination[i])(Al, x, bl, order);
                time -= timestamp();
            LIKWID_MARKER_STOP(MARKER_NAME);

            Matrix_Vector_mul(A, x, r, order); /* r = Ax */
            Vector_sub(r, b, r, order);        /* r = Ax - b */

            /* Impressao dos valores calculados */
            printf("[%d]\n", i);

            printf("timestamp: %lf\n", fabs(time));

            puts("Vector x:");
                Vector_print(x, order);

            puts("Residue y:");
                Vector_print(r, order);

            /* Liberando memoria das estruturas auxiliares */
            Matrix_destroy(Al, order);
            Vector_destroy(bl);
        }

        puts("--------------------------");

        fgets(BUFFER, B_SIZE, stdin); /* Ler o readme */ //getchar(); // '\n' || EOF  while (getchar() != '\n') 

        Matrix_destroy(A, order);
        Vector_destroy(b);
        Vector_destroy(x);
        Vector_destroy(r);
    }

    LIKWID_MARKER_CLOSE;

    return 0;
}

