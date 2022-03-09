# Tema2-Templul-Magic
A doua temă de la PCLP (Programarea Calculatoarelor și Limbaje de Programare), Anul I, Semestrul I

# Task 1 - Cuvinte magice (40p)
Cum intri în templul magic te trezești într-o cameră uriașă sub forma unei matrici de dimensiune N * M. O voce îți spune că te afli în templul lui magic și că pentru a trece la camera următoare trebuie să te miști prin cameră (prin matrice) după un traseu bine stabilit. Pentru a face lucrurile mai interesante, vocea îți spune că traseul necesar trebuie decodificat de către tine apoi îți spune un cod magic.

Pe pereții camerei sunt instrucțiunile pentru a înțelege codul mistic:

Un cod descrie traseul pe care trebuie să îl urmezi în cameră.
Codul poate fi format din oricâte cuvinte magice separate prin spațiu (fiecare cuvânt descriind un singur pas din traseu).
Cuvintele sunt de 3 tipuri:

1. Cuvintele care încep cu litera ‘a’ sunt de forma “ax1x2x3x4” unde xi sunt cifre (1⇐ i ⇐ 4). Fiecare cifră este corespunzătoare unei direcții de mișcare (x1 – dreapta , x2 – sus, x3 – stânga, x4 - jos în matrice). Cifra maximă dictează mișcarea din traseu corespunzătoare.

Ex: Codul “a1235” are cifra maximă (5) pe poziția lui x4, deci următoarea mișcare din traseu este în jos.

2. Cuvintele care încep cu litera ‘b’ sunt de forma “bx1x2…xn” unde xi sunt cifre (1⇐ i ⇐ n). Considerăm numărul format din cifrele “x1x2…xn” ca un număr K. Fie X numărul format din ultimele 2 cifre ale lui K (xn-1xn). În funcție de proprietățile de palindrom și prim ale lui K, respectiv X avem următoarele 4 situații:

K palindrom, X prim: stânga
K palindrom, X NU este prim: dreapta
K NU este palindrom, X prim: sus
K NU este palindrom, X NU este prim: jos
Ex: Codul “b121” are K = 121 și X = 21. K este palindrom și X nu este prim ⇒ următoarea mișcare din traseu este în dreapta.

3. Cuvinte care încep cu litera ‘c’ sunt de forma “cnkx1x2…xn”, unde n, k, xi sunt cifre. Fie S suma primelor k cifre luate din k în k în mod circular. S = x0 + xk + x2k + … (dacă indicele trece peste n atunci se resetează la 0). În funcție de restul împărțirii lui S la 4 avem următoarele situații:

S % 4 = 0 ⇒ stânga
S % 4 = 1 ⇒ sus
S % 4 = 2 ⇒ dreapta
S % 4 = 3 ⇒ jos
Ex: Codul “c64123456” are n = 6 (6 cifre), k = 4 și cifrele 123456. Suma dorită este: S = x0 + x4 + x8 % 6 + x12 % 6 = 1 + 5 + 3 + 1 = 10 Restul împărțirii este: S % 4 = 10 % 4 = 2 ⇒ următoarea mișcare din traseu este în dreapta.

Task 1.1 - Cuvinte magice tipul 'a' (8p)
Sa se determine traseul corect pentru cuvinte doar de tipul 'a'.

Task 1.2 - Cuvinte magice tipul 'b' (8p)
Sa se determine traseul corect pentru cuvinte doar de tipul 'b'.

Task 1.3 - Cuvinte magice tipul 'c' (8p)
Sa se determine traseul corect pentru cuvinte doar de tipul 'c'.

Task 1.4 - Cuvinte magice de orice tip (16p)
Sa se determine traseul corect pentru orice tip de cuvinte.

Input

Pe prima linie se află N si M (dimensiunile matricei). Pe a doua linie se află codul magic.

Output

Matricea cu traseul corect. Prima mișcare este mereu intrarea în cameră în colțul stânga sus și se notează cu 1 (matrix[0][0] = 1). Următoarele mișcări se descifrează din codul magic. După fiecare mișcare trebuie să notezi în matrice a câta mișcare a dus în poziția actuală (matrix[poziție_curentă_i][poziție_curentă_j] = nr. mișcare actuală).

Exemplu

Input:
4 4
a1235 b121 c64123456
Output:
1 0 0 0
2 3 4 0
0 0 0 0
0 0 0 0
