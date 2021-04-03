#include "tree.h"
#include "stack.h"
/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode* createBalanced(int N, FILE *f) {
    // TODO
    int value;

    if (N>0)
    {
        TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
        fscanf(f, "%d", &value);
        (root->val)=value;

        root->left= createBalanced (N/2, f);
        root->right= createBalanced(N-1-N/2, f); 
        return root; 
    }
    else return NULL;
}

/**
 * CERINTA 2
 * TODO: implementarea ITERATIVA functiei de parcurgere SRD(inordine) a unui arbore binar.
 * Stiva este implementata folosind un vector(vezi stack.h). In functia inorderIterative, se transmite
 * radacina arborelui si un vector in care sa stocati valorile obtinute in urma parcurgerii precum si numarul
 * de elemente din arbore presupus cunoscut(cel de la cerinta 1).
 * @param root - nodul radacina al arborelui creat la cerinta anterioara cu functia createBalanced
 * @param arr - vector in care trebuie sa adaugati nodurile arborelui pe masura ce il parcurgeti
 * @param size - numarul de noduri din arbore.
 * HINT: Pentru implementare folositi-va de implementarea stivei, vedeti fisierul stack.h
 * OBSERVATIE: Odata parcurs un nod, acesta trebuie adaugat in vectorul arr. Trebuie adaugat tot nodul, NU valoarea.
 */
void inorderIterative(TreeNode* root, TreeNode **arr, int size) {
    // TODO
    Stack *S = createStack(size); 
    int i = 0;

    while (1) 
    { 
        while (root) 
        { 
            push(S, root); 
            root=root->left; 
        }
    if (isEmpty(S)) break;

    root = pop(S);
    
    //procesam datele (in cazul de fata le adaugam in vector)
    arr[i] = root;
    i++;

    root = root ->right;
    }


}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode* root) {
    // TODO
    if (root == NULL) return;
  
    //parcurgem arborele in postordine si stergem mai intai 
    //subarborele stang dupa care il stergem pe cel drept
    deleteTree(root->left);
    deleteTree(root->right);
    
    free(root);
}

/**
 * CERINTA 4
 * TODO: Implementarea functiei pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date(LCA)
 *  pentru doua noduri n1 si n1.LCA este cel mai adanc(de jos nod) care ii are pe n1 si n1 ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */ 
TreeNode* LCA(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    // TODO 
    //daca nodul e NULL se returneaza NULL
    if (root == NULL) return NULL;
  
    //daca nodul are valoarea n1 sau n2 se returneaza acel nod
    if (root->val == n1->val || root->val == n2->val)
        return root;
  
    //daca nu este NULL si nu contine n1 sau n2 se cauta in arborele stang si arborele drept
    TreeNode *lca_l = LCA(root->left, n1, n2);
    TreeNode *lca_r = LCA(root->right, n1, n2);

    // daca lca_l si lca_r sunt nenule rezulta ca nodul n1 e prezent in lca_l si n2 e prezent in lca_r (sau invers)
    if(lca_l != NULL && lca_r != NULL) return root;
    else if (lca_l != NULL) return lca_l;
    return lca_r;
}