#include "tree.h"
#include "stack.h"
/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode *createBalanced(int N, FILE *f)
{
    if (N > 0)
    {
        TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
        fscanf(f, "%d", &root->val);
        root->left = createBalanced(N / 2, f);
        root->right = createBalanced(N - 1 - N / 2, f);
        return root;
    }
    else
        return NULL;
    // TODO
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
void inorderIterative(TreeNode *root, TreeNode **arr, int size)
{
    int nr = 0;
    Stack *parcurgere = createStack(size);
    while (1)
    {
        while (root != NULL)
        {
            push(parcurgere, root);
            root = root->left;
        }
        if (isEmpty(parcurgere))
            break;
        root = pop(parcurgere);
        arr[nr] = root;
        nr++;
        root = root->right;
    }
    // TODO
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
    // TODO
}

/**
 * CERINTA 4
 * TODO: Implementarea functiei pentru gasirea celui mai apropiat stramos comun(LCA) a doua noduri date(LCA)
 *  pentru doua noduri n1 si n1.LCA este cel mai adanc(de jos nod) care ii are pe n1 si n1 ca descendenti
 * @param root - nodul radacina al arborelui
 * @param n1 - nodul 1 pentru cautare LCA
 * @param n2 - nodul 2 pentru cautare LCA
 */
TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    TreeNode *lca_stanga, *lca_dreapta;
    if (root == n1 || root == n2)
    {
        return root;
    }
    else
    {
        if (root != NULL)
        {
            lca_stanga = LCA(root->left, n1, n2);
            lca_dreapta = LCA(root->right, n1, n2);
            if (lca_stanga != NULL && lca_dreapta != NULL)
                return root;
            return lca_stanga;
        }
        else
            return NULL;
    }
    // TODO
}