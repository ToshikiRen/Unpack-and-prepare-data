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
    if (!N)
        return NULL;

    static int data;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    fscanf(f, "%i", &data);
    root->val = data;

    root->left = createBalanced(N / 2, f);
    root->right = createBalanced(N - 1 - N / 2, f);

    return root;
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
    int count = -1;
    Stack *my_stack = createStack(size / 2);

    while (1)
    {
        while (root)
        {
            push(my_stack, root);
            root = root->left;
        }

        if (isEmpty(my_stack))
            break;

        root = pop(my_stack);
        arr[++count] = root;

        root = root->right;
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
    if (!root)
        return root;

    if ((root->val == n1->val) || (root->val == n2->val))
        return root;

    TreeNode *seek_left = LCA(root->left, n1, n2);
    TreeNode *seek_right = LCA(root->right, n1, n2);

    if ((seek_left) && (seek_right))
        return root;
        
    if (seek_left)
        return seek_left;
    return seek_right;
}