#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define N2 20
#define ascii0 48

int prim(int x)
{
    int i;
    int prim = 1;
    if (x > 2)
        for (i = 2; i < x / 2; i++)
            if (x % i == 0)
            {
                prim = 0;
                break;
            }
    return prim;
}

int palindrom(int x)
{
    int a, b;
    b = x;
    a = 0;
    while (x > 0)
    {
        a = a * 10 + (x % 10);
        x = x / 10;
    }
    if (a == b)
        return 1;
    else
        return 0;
}
void aword(char w[N2], int x, int y, int **drum, int contor)
{
    int i, k, nr, maxim = 0;
    for (i = 1; i <= 4; i++)
    {
        nr = w[i] - ascii0;
        if (nr > maxim)
        {
            maxim = nr;
            k = i;
        }
    }
    switch (k)
    {
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
void bword(char w[N2], int x, int y, int **drum, int contor)
{
    int K = 0, X = 0, i, nr, pal, pr;
    for (i = 1; i < strlen(w); i++)
    {
        nr = w[i] - ascii0;
        K = K * 10 + nr;
        if (i >= strlen(w) - 2)
            X = X * 10 + nr;
    }
    pal = palindrom(K);
    pr = prim(X);
    if (pal == 0)
    {
        if (pr == 0)
            y++;
        else
            y--;
    }
    else
    {
        if (pr == 0)
            x++;
        else
            x--;
    }
    drum[y][x] = contor;
}
void cword(char *w, int x, int y, int **drum, int contor)
{
    int s = 0, i, v[N2], n, k;
    n = w[1] - ascii0;
    k = w[2] - ascii0;
    for (i = 0; i < n; i++)
        v[i] = w[i + 3] - ascii0;
    for (i = 0; i < k; i++)
        s = s + v[(i * k) % n];
    switch (s % 4)
    {
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
int main()
{
    int n, m, **drum, i, j, x = 1, y = 1, contor = 1;
    char *rand, *cuv;
    scanf("%d", &n);
    scanf("%d\n", &m);
    rand = malloc(N * sizeof(char));
    cuv = malloc(N2 * sizeof(char));
    fgets(rand, N-1, stdin);

    // Alocare memorie ptr matrice
    drum = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        drum[i] = calloc(m, sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            drum[i][j] = 0;
    drum[y][x] = 1;
    cuv = strtok(rand, " ");
    while (cuv != NULL)
    {
        contor++;
        switch (cuv[0])
        {
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

    //Afisare drum
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%3d", drum[i][j]);
        printf("\n");
    }
    return 0;
}