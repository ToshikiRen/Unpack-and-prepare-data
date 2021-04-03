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
    int x;

    if (N > 0)
    {
        fscanf(f, "%d", &x);
        TreeNode *root = (TreeNode*)malloc(sizeof(TreeNode));
        root->val = x;
        root->left = createBalanced(N/2, f);
        root->right = createBalanced(N - 1 - N/2, f);

        return root;
    }

    return NULL;
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
    Stack *stack;
    stack = createStack(size);
    int counter = 0; // index pentru arr; la final este egal cu nr de noduri din arbore si din arr

    while (counter < size) // cat timp mai am noduri in arbore
    {
        while (root)
        {
            push(stack, root);
            root = root->left; //merg pana la cel mai din stanga nod
        }

        if (!isEmpty(stack))
        {
            root = pop(stack); // scot nodul din stiva
            arr[counter++] = root; // il adaug in arr
            root = root->right; // ma mut la dreapta
        }
        else break;
    }
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
    TreeNode *lca_l, *lca_r;
    
    if(root == NULL)
        return NULL;
    if(root->val == n1->val || root->val == n2->val)
        return root;
    else
        if (root != NULL)
        {
            lca_l = LCA(root->left, n1, n2);
            lca_r = LCA(root->right, n1, n2);
            if(lca_l != NULL && lca_r != NULL)
                return root;
            else
                if(lca_l != NULL && lca_r == NULL)
                    LCA(lca_l, n1, n2);
                else
                    if(lca_l == NULL && lca_r != NULL)
                         LCA(lca_r, n1, n2);
        }    
}