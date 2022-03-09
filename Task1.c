#include "utils.h"
#define N 150
#define N2 20
#define ascii0 48
#define ten 10

int prim(int x) {
    int i = 0;
    int prim = 1;
    if (x > 2) {
        for (i = 2; i < x / 2; i++)
            if (x % i == 0) {
                prim = 0;
                break;
            }
    }
    return prim;
}

int palindrom(int x) {
    int a = 0, b = 0;
    b = x;
    a = 0;
    while (x > 0) {
        a = a * ten + (x % ten);
        x = x / ten;
    }
    if (a == b)
        return 1;
    else
        return 0;
}
void aword(char w[N2], int x, int y, int **drum, int contor) {
    int i = 0, k = 0, nr = 0, maxim = 0;
    for (i = 1; i <= 4; i++) {
        nr = w[i] - ascii0;
        if (nr > maxim) {
            maxim = nr;
            k = i;
        }
    }
    switch (k) {
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;
    }
    drum[y][x] = contor;
}
void bword(char w[N2], int x, int y, int **drum, int contor) {
    int K = 0, X = 0, i = 0, nr = 0, pal = 0, pr = 0;
    for (i = 1; i < strlen(w); i++) {
        nr = w[i] - ascii0;
        K = K * ten + nr;
        if (i >= strlen(w) - 2)
            X = X * ten + nr;
    }
    pal = palindrom(K);
    pr = prim(X);
    if (pal == 0 && pr == 0)
            y++;
    else if (pal == 0 && pr != 0)
            y--;
    else if (pal != 0 && pr == 0)
            x++;
    else if (pal != 0 && pr != 0)
            x--;
    drum[y][x] = contor;
}
void cword(char *w, int x, int y, int **drum, int contor) {
    int s = 0, i = 0, v[N2], n = 0, k = 0;
    n = w[1] - ascii0;
    k = w[2] - ascii0;
    for (i = 0; i < n; i++)
        v[i] = w[i + 3] - ascii0;
    for (i = 0; i < k; i++)
        s = s + v[(i * k) % n];
    switch (s % 4) {
    case 0:
        x--;
        break;
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    }
    drum[y][x] = contor;
}

void SolveTask1() {
    int n = 0, m = 0, **drum = NULL, i = 0, j = 0, x = 0, y = 0, contor = 1;
    char *rand = NULL, *cuv = NULL;
    scanf("%d", &n);
    scanf("%d\n", &m);
    rand = malloc(N * sizeof(char));
    cuv = malloc(N2 * sizeof(char));
    fgets(rand, N - 1, stdin);

    // Alocare memorie matrice + initializare

    drum = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        drum[i] = calloc(m, sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            drum[i][j] = 0;
    drum[y][x] = 1;

    // Traseu

    cuv = strtok(rand, " ");
    while (cuv != NULL) {
        contor++;
        switch (cuv[0]) {
        case 'a':
            aword(cuv, x, y, drum, contor);
            break;
        case 'b':
            bword(cuv, x, y, drum, contor);
            break;
        case 'c':
            cword(cuv, x, y, drum, contor);
            break;
        }
        if (drum[y][x + 1] == contor)
            x++;
        else if (drum[y][x - 1] == contor)
            x--;
        else if (drum[y + 1][x] == contor)
            y++;
        else if (drum[y - 1][x] == contor)
            y--;

        cuv = strtok(NULL, " ");
    }

    // Afisare drum

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%3d", drum[i][j]);
        printf("\n");
    }
}
