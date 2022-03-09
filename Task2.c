#include "utils.h"
#define ten 10
#define nine 9
#define ts 26
#define M 1001
#define N 15

char *caesar(int k, char *s) {
    int n = 0, i = 0, nr = 0;
    char c = 0;
    n = (int) strlen(s);
    for (i = 0; i < n; i++) {
        c = s[i];
        if (isdigit(c) != 0) {
            if (c - (k % ten) >= '0')
                c = (char)(c - k % ten);
            else
                c = (char)(c - k % ten + ten);
        } else if (islower(c) != 0) {
            if ((char)(c - (k % ts)) >= 'a')
                c = (char)(c - k%ts);
            else
                c = (char)(c - k % ts + ts);
        } else if (isupper(c) != 0) {
            if (c - (k % ts) >= 'A')
                c = (char)(c - k%ts);
            else
                c = (char)(c - k % ts + ts);
        }
        s[i] = c;
    }
    return s;
}

void vigenere(char *k, char *s) {
    int n = 0;
    int lit = 0;
    int i = 0, nr = 0, cheie = 0;
    char c = 0;
    lit = (int)strlen(k) - 1;
    n = (int)strlen(s);
    for (i = 0; i < n; i++) {
        cheie = (int)(k[(i % lit)] - 'A');
        c = s[i];
        if (isdigit(c) != 0) {
            if (c - (cheie % ten) >= '0')
                c = (char)(c - cheie % ten);
            else
                c = (char)(c - cheie % ten + ten);
        } else if (islower(c) != 0) {
            if ((char)(c - (cheie % ts)) >= 'a')
                c = (char)(c - cheie%ts);
            else
                c = (char)(c - cheie% ts + ts);
        } else if (isupper(c) != 0) {
            if (c - (cheie % ts) >= 'A')
                c = (char)(c - cheie%ts);
            else
                c = (char)(c -cheie % ts + ts);
        }
        s[i] = c;
    }
    printf("%s", s);
}

void addition(int k, char *n1, char *n2) {
    // decriptare

    int lg1 = (int)strlen(n1) - 1;
    int lg2 = (int)strlen(n2) - 1;
    strncpy(n1, caesar(k, n1), M);
    strncpy(n2, caesar(k, n2), M);
    int nr = 0, plus = 0, lg = 0, i = 0;

    // n2 are mai multe cifre decat n1

    if (lg1 > lg2) {
        lg = lg1 + 1;
        int t = 0;
        t = lg1;
        lg1 = lg2;
        lg2 = t;
        char *temp = NULL;
        temp = (char *)malloc(M * sizeof(char));
        strncpy(temp, n1, M);
        strncpy(n1, n2, M);
        strncpy(n2, temp, M);
        free(temp);
    } else {
        lg = lg2 + 1;
    }
    // calculare suma

    char sum[M] = {0};
    for (i = 0; i < lg; i++) {
        // calculam cifra curenta in nr

        nr = plus;
        if (lg1 >= i + 1)
            nr += n1[lg1 - 1 - i] - '0';
        if (lg2 >= i + 1)
            nr += n2[lg2 - 1 - i] - '0';

        // verificare cifra

        if (nr > nine) {
            sum[lg - 1 - i] = (char)('0' + nr % ten);
            plus = 1;
        } else {
            sum[lg - 1 - i] = (char)('0' + nr);
            plus = 0;
        }
    }
    while (sum[0] == '0') {
        for (i = 0; i < strlen(sum); i++) {
            sum[i] = sum[i + 1];
        }
    }
    printf("%s\n", sum);
}

void SolveTask2() {
    int useless = 0;
    char *s = NULL, *tip = NULL;
    scanf("%d\n", &useless);
    tip = (char*)malloc(N * sizeof(char));
    s = (char*)malloc(M * sizeof(char));
    fgets(tip, N, stdin);
    if (tip[0] == 'c') {
        int k = 0;
        scanf("%d \n", &k);
        fgets(s, M - 1, stdin);
        strncpy(s, caesar(k, s), strlen(s)+1);
        printf("%s", s);
    } else if (tip[0] == 'v') {
        char *k = NULL;
        k = (char*)malloc(N * sizeof(char));
        fgets(k, N - 1, stdin);
        fgets(s, M - 1, stdin);
        vigenere(k, s);
        free(k);
    } else if (tip[0] == 'a') {
        int k = 0;
        char *n1 = NULL, *n2 = NULL;
        n1 = (char*)malloc(M * sizeof(char));
        n2 = (char*)malloc(M * sizeof(char));
        scanf("%d\n", &k);
        fgets(n1, M - 1, stdin);
        fgets(n2, M - 1, stdin);
        addition(k, n1, n2);
        free(n1);
        free(n2);
    }
    free(s);
    free(tip);
}
