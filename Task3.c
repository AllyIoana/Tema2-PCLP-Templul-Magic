#include "utils.h"
#define N 10000
#define N2 100

void SolveTask3() {
    char *s = NULL, **cuvinte = NULL, *cuv = NULL;
    char **grup1 = NULL, **grup2 = NULL;
    int *contor = NULL;
    int i = 0, j = 0, grupuri = 0, totalcuvinte = 0, gasit = 0;

    // Alocare memorie

    s = malloc(N * sizeof(char));
    cuv = malloc(N2 * sizeof(char));
    contor = malloc(N * sizeof(int));

    grup1 = malloc(N * sizeof(char *));
    for (i = 0; i < N; i++)
        grup1[i] = calloc(N2, sizeof(char));
    grup2 = malloc(N * sizeof(char *));
    for (i = 0; i < N; i++)
        grup2[i] = calloc(N2, sizeof(char));
    cuvinte = malloc(N * sizeof(char *));
    for (i = 0; i < N; i++)
        cuvinte[i] = calloc(N2, sizeof(char));

    // Cititre cuvinte

    while (fgets(s, N * sizeof(char), stdin) != NULL) {
        cuv = strtok(s, ",.;! \n");
        while (cuv != NULL) {
            strncpy(cuvinte[++totalcuvinte], cuv, N2);
            cuv = strtok(NULL, ",.;! \n");
        }
    }

    // Grupare cuvinte

    cuv = cuvinte[1];
    for (i = 2; i <= totalcuvinte; i++) {
        // grup format din cuv si cuvinte[i]

        gasit = 0;
        for (j = 1; j < grupuri; j++) {
            if (strcmp(cuv, grup1[j]) == 0) {
                if (strcmp(cuvinte[i], grup2[j]) == 0) {
                    // am gasit grupul
                    gasit = 1;
                    contor[j]++;
                    break;
                }
            }
        }
        if (gasit == 0) {
            grupuri++;
            strncpy(grup1[grupuri], cuv, N2);
            strncpy(grup2[grupuri], cuvinte[i], N2);
            contor[grupuri] = 1;
        }
        strncpy(cuv, cuvinte[i], N2);
    }
    printf("%d\n", grupuri);
    for (i = 1; i <= grupuri; i++)
        printf("%s %s %d\n", grup1[i], grup2[i], contor[i]);
    // Eliberare memorie

    free(s);
    free(cuv);
    free(contor);
    for (i = 0; i < N2; i++)
        free(grup1[i]);
    free(grup1);
    for (i = 0; i < N2; i++)
        free(grup2[i]);
    free(grup2);
    free(cuvinte);
}
