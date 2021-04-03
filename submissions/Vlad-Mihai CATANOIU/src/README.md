<h2 align="center">
 lab-05: Arbori binari
</h2>

<h4>Cerințe:</h4>

1. Creati un arbore binar folosind functia (CreateBalanced(int N) – slide 23 – C5). Toate elementele/nodurile din arbore au valori (chei).

2. Parcurgeti arborele in inordine (SRD) – folosind o functie implementata iterativ (idee: similar cu parcurgerea in preordine vezi sliduri 17-20 – C5).
Idee implementare: utilizati implementarea data a stivei.
Stiva este implementata folosind un vector (vezi stack.h). In functia inorderIterative, se transmite:
    * radacina arborelui si un vector in care se stocheaza valorile obtinute in urma parcurgerii, precum si numarul de elemente din arbore (presupus cunoscut).

3. Implementati o functie pentru eliberarea spatiul ocupat de un arbore binar (iterativ sau recursiv).

**Idee solutie recursiva** – parcurgeti arborele in postordine (SDR) si eliberati spatiul pentru nodurile din stanga si dreapta inainte de a elibera spatiul ocupat de radacina. Se elibereaza mai intai spatiul ocupat de nodurile cele mai din stanga jos, apoi cele din dreapta jos.

**Idee solutie iterativa** – parcurgeti arborele pe niveluri. Stergeti fiecare nod din coada dupa ce ati adaugat copiii acelui nod (in coada) pentru a fi procesati. Se elibereaza mai intai spatiul  ocupat de nodurile cele mai de sus, tinand minte adresele copiilor.

4. Implementati o functie (iterativ sau recursiv) pentru gasirea celui mai apropiat stramos comun  a doua noduri (Lowest Common Ancestor - LCA) date prin valoarea lor (toate elementele din arbore au valori distincte).
LCA a doua noduri a si b este cel mai adanc (de jos nod) care ii are pe a si b ca descendenti.

![lca](https://user-images.githubusercontent.com/49961252/112722850-64e85e00-8f14-11eb-871f-80dcce5dfe74.png)

Exemplu: LCA pentru 6 si 1 e 8
{4, 8, 5, 7} - calea de la radacina la nodul 6
{4, 8}  - calea de la radacina la nodul 1

**Solutie iterativa:** se salveaza caile de la radacina la nodul a si de la radacina la nodul b in 2 vectori. 
Apoi se parcurg vectorii pana cand se gasesc 2 valori diferite (sau nu mai sunt elemente in vreunul dintre cei doi vectori). Ultima valoare egala era cea a LCA. 

**Solutie recursiva:** Se cauta nodul din arbore care are nodul a intr-un subarbore si nodul b in celalalt subarbore.
Se foloseste parcurgerea in postordine si se verifica la fiecare pas:
- daca nodul investigat e NULL, se returneaza NULL 
- daca nodul investigat are valoarea (cheia) a sau b, se returneaza adresa acelui nod (este de interes ca l-am gasit). OBS: Daca o valoare (cheie) este stramos al celeilalte, atunci nodul care o contine e LCA
- daca nodul nu este NULL si nu contine valoarea (cheia) a sau b atunci se cauta in subarborele stang si, respectiv, drept dupa cele 2 chei; fiecare cautare isi stocheaza rezultatul intr-o variabila locala astfel: daca se gaseste vreo cheie in subarborele stang, se salveaza adresa nodului in lca_l si daca se gaseste in cel drept in lca_r
- daca in urma cautarii lca_l si lca_r sunt nenule inseamna ca nodul a este prezent intr-un subarbore si nodul b in celalalt - atunci nodul curent e LCA => se returneaza acest nod; altfel, LCA se gaseste in subarborele stang sau drept (lca_l sau lca_r) care se returneaza astfel incat cautarea sa continue






