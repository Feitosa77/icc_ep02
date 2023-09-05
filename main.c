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

        for (i = 0; i < N_ELIMINATIONS; ++i) {
            Al = Matrix_clone(A, order, order);
            bl = Vector_clone(b, order);

            LIKWID_MARKER_START("gaussian-elimination");
                time = timestamp();
                    (*elimination[i])(Al, x, bl, order);
                time -= timestamp();
            LIKWID_MARKER_STOP("gaussian-elimination");

            Matrix_Vector_mul(A, x, r, order); /* r = Ax */
            Vector_sub(r, b, r, order);        /* r = Ax - b */

            printf("[%d]\n", i);

            printf("timestamp: %lf\n", fabs(time));

            puts("Vector x:");
                Vector_print(x, order);

            puts("Residue y:");
                Vector_print(r, order);

            Matrix_destroy(Al, order);
            Vector_destroy(bl);
        }

        puts("--------------------------");

        Matrix_destroy(A, order);
        Vector_destroy(b);
        Vector_destroy(x);
        Vector_destroy(r);

        fgets(BUFFER, B_SIZE, stdin); /* Ler o readme */ //getchar(); // '\n' || EOF  while (getchar() != '\n') 
    }

    LIKWID_MARKER_CLOSE;

    return 0;
}

