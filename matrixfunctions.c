#include "matrixfunctions.h"
#include <stdlib.h>


double find_determinant(double **matrix) {
    return ((**matrix) * (*(*(matrix + 1) + 1))) - (*(*matrix + 1) * **(matrix + 1));
}

double **get_inverse(double **matrix) {
    double **inverse = malloc(2 * sizeof(double *));
    for (int i = 0; i < 2; i++) {
        *(inverse + i) = malloc(2 * sizeof(double));
    }

    double determinant = find_determinant(matrix);

    **inverse = *(*(matrix + 1) + 1) / determinant;
    **(inverse + 1) = -1 * **(matrix + 1) / determinant;
    *(*inverse + 1) = -1 * *(*matrix + 1) / determinant;
    *(*(inverse + 1) + 1) = **matrix / determinant;

    return inverse;
}

double *get_dot_product(double **matrix_a, double *matrix_b) {
    double *solution = malloc(2 * sizeof(double));
    double *sum = malloc(sizeof(double));
    for (int i = 0; i < 2; i++) {
        *sum = 0;
        for (int j = 0; j < 2; j++) {
            *sum += *(*(matrix_a + i) + j) * *(matrix_b + j);
        }
        *(solution + i) = *sum;
    }
    free(sum);
    return solution;
}
