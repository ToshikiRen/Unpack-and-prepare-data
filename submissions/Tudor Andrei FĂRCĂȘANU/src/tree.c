#include "tree.h"
#include "stack.h"
#include "utils.h"
/**
 * CERINTA 1
* TODO: Implementarea functiei createBalanced descrisa in curs.
* @param N - numarul de noduri din arbore
* @param f - fisierul din care se vor citi valorile pentru nodurile arborelui
* Valorile sunt stocate in fisier sub forma: 1 2 3 4(pe un rand separate de un spatiu) 
*/
TreeNode *createBalanced(int N, FILE *f)
{
    int data;
    if (N > 0)
    {
        TreeNode *rad = (TreeNode *)malloc(sizeof(TreeNode));
        fscanf(f, "%d", &data);
        (rad->val) = data;
        rad->left = createBalanced(N / 2, f);
        rad->right = createBalanced(N - 1 - N / 2, f);
        return rad;
    }
    else
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

    int i = 0;
    Stack *S = createStack(size);

    while (1)
    {
        while (root)
        {
            push(S, root);
            root = root->left;
        }
        if (isEmpty(S))
            break;
        root = pop(S);
        if (root != NULL)
        {
            printf("%d ", root->val);
            arr[i++] = root;
        }
        root = root->right;
    }
    // int i=0;
    // Stack *S = createStack(size);
    // while (1)
    // {
    //     while (root)
    //     {

    //         printf("%d ", root->val);
    //         arr[i++]=root;
    //         push(S, root);
    //         root = root->left;
    //     }
    //     if (isEmpty(S)) break;
    //     root = pop(S);
    //     root = root-> right;
    // }
}

/**
 * CERINTA 3
 * TODO: Implementarea functiei pentru eliberarea spatiului ocupat de un arbore.
 * @param root - radacina arborelui ce trebuie eliberat.
 */
void deleteTree(TreeNode *root)
{
    int i = 0;
    Stack *S = createStack(getNumberOfNodes(root));
    TreeNode *temp;
    while (1)
    {
        while (root)
        {
            push(S, root);
            root = root->left;
        }
        if (isEmpty(S))
            break;
        root = pop(S);
        temp = root;
        root = root->right;
        if (temp != NULL)
        {
            TreeNode *ant = peek(S);
            if (ant != NULL)
            {
                if (ant->left == temp)
                    ant->left = NULL;
                if (ant->right == temp)
                    ant->right = NULL;
            }
            free(temp);
        }
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

bool pathfind(TreeNode *rot, TreeNode *node, Stack **st)
{

    push(*st, rot);
    if (node == rot)
    {
        return true;
    }
    if ((rot->left != NULL && pathfind(rot->left, node, st) == true) || (rot->right != NULL && pathfind(rot->right, node, st) == true))
    {
        return true;
    }
    pop(*st);
    return false;
}
TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    TreeNode *cop1 = root;
    TreeNode *cop2 = root;
    int n = getNumberOfNodes(cop1);
    int i=0;
    Stack *sta1 = createStack(n);
    Stack *sta2 = createStack(n);
    pathfind(cop1, n1, &sta1);
    pathfind(cop2, n2, &sta2);
    for(i=0; i<(sta1->top)+1 && i<(sta2->top)+1;i++)
    {
        if(sta1->arr[i]!=sta2->arr[i])
        {
            if (sta1->arr[i - 1] != NULL)
                return sta1->arr[i - 1];
            if (sta2->arr[i - 1] != NULL)
                return sta2->arr[i - 1];
        }
    }
        return sta1->arr[i-1];
}
