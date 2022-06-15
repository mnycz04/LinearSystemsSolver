#include <stdio.h>
#include <stdlib.h>
#include "matrixfunctions.h"
#include "string.h"


int main(void) {
    double *constants = malloc(2 * sizeof(double));
    double **coefficients = malloc(2 * sizeof(double*));

    for (int i = 0; i < 2; i++) {
        *(coefficients + i) = malloc(2 * sizeof(double));
    }

    printf("=====Linear System of Equations Calculator=====\n\n");

    while (1) {

        char *input = malloc(10 * sizeof(char));
        for (int i = 0; i < 2; i++) {
            printf("Equation 1:\n");
            for (int j = 0; j < 2; j++) {
                printf("\tCoeff %i: ", j + 1);
                scanf("%s", input);
                if (strcmp(input, "quit") == 0) {
                    goto exit_program;
                }
                *(*(coefficients + i) + j) = atof(input);
            }

            printf("\tConstant: ");
            scanf("%s", input);
            if (strcmp(input, "quit") == 0) {
                goto exit_program;
            }
            *(constants + i) = atof(input);
        }

        double **inverse = get_inverse(coefficients);

        double *solution = get_dot_product(inverse, constants);
        printf("%lf, %lf\n\n", *solution, *(solution + 1));
        free(solution);
    }
    exit_program:

    for (int i = 0; i < 2; i++) {
        free(*(coefficients + i));
    }
    free(coefficients);
    free(constants);
    return 0;
}
