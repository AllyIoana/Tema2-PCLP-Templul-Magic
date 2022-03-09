# Tema2-Templul-Magic
A doua temă de la PCLP (Programarea Calculatoarelor și Limbaje de Programare), Anul I, Semestrul I

# Task 1 - Cuvinte magice
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

Task 1.1 - Cuvinte magice tipul 'a'
Sa se determine traseul corect pentru cuvinte doar de tipul 'a'.

Task 1.2 - Cuvinte magice tipul 'b'
Sa se determine traseul corect pentru cuvinte doar de tipul 'b'.

Task 1.3 - Cuvinte magice tipul 'c'
Sa se determine traseul corect pentru cuvinte doar de tipul 'c'.

Task 1.4 - Cuvinte magice de orice tip
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

# Task 2 - Vocea stranie
La ieșirea din labirint, auzi din nou aceeași voce stranie, însă, de data aceasta, nu mai poți înțelege cuvintele pe care le rostește. Brusc, îți dai seama că mesajele pe care vocea le spune sunt criptate. Fiind un bun programator, ai decis să încerci să le descifrezi.

Task 2.1 
Prima variantă la care te gândești, cifrul Caesar, obține un text criptat pe baza unui mesaj (denumit plaintext) și a unei chei (un număr întreg) în modul următor: fiecare literă din mesaj este “rotită” cu valoarea specificată de cheie. Spre exemplu, șirul “abCZ” rotit cu cheia 3 devine “deFC”. În plus față de această funcționalitate clasică, vom considera că și cifrele se pot “roti”. Adică, șirul “1239” rotit cu cheia 3 devine “4562”. Descifrarea este întocmai operația opusă: pornind de la un text criptat, pentru care se cunoaște cheia cu care a fost criptat, se poate afla mesajul inițial.

Se cere să se afișeze mesajul inițial, obținut în urma decriptării textului criptat, cunoscându-se cheia de criptare. În acest sens, se dă un input de forma:

2
caesar
K
S
.....
K -> cheia cu care a fost criptat șirul
S -> textul criptat
Task 2.2
Cel de-al doilea cifru, Vigenère, se bazează tot pe un mesaj și o cheie, care de data aceasta este un șir de majuscule. Pentru a obține textul criptat, se repetă cheia de-a lungul mesajului, iar fiecare literă din mesaj este “rotită” pe baza poziției în alfabet a literei corespunzătoare din cheie. În mod asemănător cu cerința anterioară, și cifrele se vor “roti” în funcție de litera corespunzătoare din cheie. Exemplu de criptare:

Mesaj: abc1234
Cheie: ABC
Text criptat: ace1354

Explicatie:
Mesaj:          abc1234
Cheie extinsă:  ABCABCA
A are poziția 0 => caracterele corespunzătoare lui A nu se vor modifica (a->a, 1->1, 4->4)
B are poziția 1 => caracterele corespunzătoare lui B se deplasează cu 1 (b->c, 2->3)
C are poziția 2 => caracterele corespunzătoare lui C se deplasează cu 2 (c->e, 3->5)
Se cere să se afișeze mesajul inițial, obținut în urma decriptării unui text criptat, cunoscându-se cheia de criptare. Se va primi un input de forma:

2
vigenere
K
S
.....
K -> cheia cu care a fost criptat șirul
S -> textul criptat

Task 2.3
Ai realizat că vocea folosește cifrul Caesar pentru criptarea mesajelor, așa că atunci când îți spune două numere mari, te gândești să calculezi suma lor, după ce le decriptezi. Deci, cerința constă în adunarea a două numere mari, care trebuie stocate sub forma de șir de caractere. Numerele sunt inițial criptate folosind cifrul Caesar descris la cerința 2.1 și trebuie decriptate înainte de a calcula suma lor. Se va primi un input de forma:

2
addition
K
N1
N2
.....
K -> cheia cu care au fost criptate numerele
N1, N2 -> cele două numere mari, criptate cu cheia K
Se cere să se afișeze suma celor două numere mari, după ce au fost decriptate.

Exemplu:

K = 3, N1 = "123", N2 = "456" => rezultatul este "1013"
Explicație: 
"123" decriptat cu K = 3 este "890"
"456" decriptat cu K = 3 este "123"
"890" + "123" = "1013"

# Task 3 - Ajutorul
Fiindcă ai reușit să descifrezi și să rezolvi provocările anterioare, vocea decide să îți ceară ajutorul în finalizarea unui algoritm de prezicere a cuvintelor. Vocea îți spune ca deja cunoaște frecvențele cuvintelor într-un text, dar are nevoie de tine pentru calcularea numărului de apariții a 2-gramelor, în ordinea apariției lor. O n-gramă reprezintă un grup de n elemente (cuvinte, silabe, litere, etc.) consecutive dintr-un text. Pentru acest task vom trata n-gramele ca fiind grupuri de n cuvinte consecutive. Un cuvânt este separat de spații sau newline, iar punctuația precum ',', '.', '!', ';' este ignorată. De asemenea, input-ul este case sensitive și nu este nevoie de a tranforma literele mari în mici.

Astfel, un exemplu ar consta în următorul sample test:

in:
3
The weather is nice, the sun is nice too.
The sun is yellow!
out: 
10
The weather 1
weather is 1
is nice 2
nice the 1
the sun 1
sun is 2
nice too 1
too The 1
The sun 1
is yellow 1
